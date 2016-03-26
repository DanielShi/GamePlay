#include "Base.h"
#include "Effect.h"
#include "FileSystem.h"
#include "Game.h"

#define OPENGL_ES_DEFINE  "OPENGL_ES"

namespace gameplay
{

// Cache of unique effects.
static std::map<std::string, Effect*> __effectCache;
static Effect* __currentEffect = NULL;

Effect::Effect() : _program(0)
{
}

Effect::~Effect()
{
    // Remove this effect from the cache.
    __effectCache.erase(_id);

    // Free uniforms.
    for (std::map<std::string, Uniform*>::iterator itr = _uniforms.begin(); itr != _uniforms.end(); ++itr)
    {
        SAFE_DELETE(itr->second);
    }

    if (_program)
    {
        // If our program object is currently bound, unbind it before we're destroyed.
        if (__currentEffect == this)
        {
            GPRHI_ASSERT( GPRHI_UseProgram(0) );
            __currentEffect = NULL;
        }

        GPRHI_ASSERT( GPRHI_DeleteProgram(_program) );
        _program = 0;
    }
}

Effect* Effect::createFromFile(const char* vshPath, const char* fshPath, const char* defines)
{
    GP_ASSERT(vshPath);
    GP_ASSERT(fshPath);

    // Search the effect cache for an identical effect that is already loaded.
    std::string uniqueId = vshPath;
    uniqueId += ';';
    uniqueId += fshPath;
    uniqueId += ';';
    if (defines)
    {
        uniqueId += defines;
    }
    std::map<std::string, Effect*>::const_iterator itr = __effectCache.find(uniqueId);
    if (itr != __effectCache.end())
    {
        // Found an exiting effect with this id, so increase its ref count and return it.
        GP_ASSERT(itr->second);
        itr->second->addRef();
        return itr->second;
    }

    // Read source from file.
    char* vshSource = FileSystem::readAll(vshPath);
    if (vshSource == NULL)
    {
        GP_ERROR("Failed to read vertex shader from file '%s'.", vshPath);
        return NULL;
    }
    char* fshSource = FileSystem::readAll(fshPath);
    if (fshSource == NULL)
    {
        GP_ERROR("Failed to read fragment shader from file '%s'.", fshPath);
        SAFE_DELETE_ARRAY(vshSource);
        return NULL;
    }

    Effect* effect = createFromSource(vshPath, vshSource, fshPath, fshSource, defines);
    
    SAFE_DELETE_ARRAY(vshSource);
    SAFE_DELETE_ARRAY(fshSource);

    if (effect == NULL)
    {
        GP_ERROR("Failed to create effect from shaders '%s', '%s'.", vshPath, fshPath);
    }
    else
    {
        // Store this effect in the cache.
        effect->_id = uniqueId;
        __effectCache[uniqueId] = effect;
    }

    return effect;
}

Effect* Effect::createFromSource(const char* vshSource, const char* fshSource, const char* defines)
{
    return createFromSource(NULL, vshSource, NULL, fshSource, defines);
}

static void replaceDefines(const char* defines, std::string& out)
{
    Properties* graphicsConfig = Game::getInstance()->getConfig()->getNamespace("graphics", true);
    const char* GPRHI_obalDefines = graphicsConfig ? graphicsConfig->getString("shaderDefines") : NULL;

    // Build full semicolon delimited list of defines
#ifdef OPENGL_ES
    out = OPENGL_ES_DEFINE;
#else
    out = "";
#endif
    if (GPRHI_obalDefines && strlen(GPRHI_obalDefines) > 0)
    {
        if (out.length() > 0)
            out += ';';
        out += GPRHI_obalDefines;
    }
    if (defines && strlen(defines) > 0)
    {
        if (out.length() > 0)
            out += ';';
        out += defines;
    }

    // Replace semicolons
    if (out.length() > 0)
    {
        size_t pos;
        out.insert(0, "#define ");
        while ((pos = out.find(';')) != std::string::npos)
        {
            out.replace(pos, 1, "\n#define ");
        }
        out += "\n";
    }
}

static void replaceIncludes(const char* filepath, const char* source, std::string& out)
{
    // Replace the #include "xxxx.xxx" with the sourced file contents of "filepath/xxxx.xxx"
    std::string str = source;
    size_t lastPos = 0;
    size_t headPos = 0;
    size_t fileLen = str.length();
    size_t tailPos = fileLen;
    while (headPos < fileLen)
    {
        lastPos = headPos;
        if (headPos == 0)
        {
            // find the first "#include"
            headPos = str.find("#include");
        }
        else
        {
            // find the next "#include"
            headPos = str.find("#include", headPos + 1);
        }

        // If "#include" is found
        if (headPos != std::string::npos)
        {
            // append from our last position for the legth (head - last position) 
            out.append(str.substr(lastPos,  headPos - lastPos));

            // find the start quote "
            size_t startQuote = str.find("\"", headPos) + 1;
            if (startQuote == std::string::npos)
            {
                // We have started an "#include" but missing the leading quote "
                GP_ERROR("Compile failed for shader '%s' missing leading \".", filepath);
                return;
            }
            // find the end quote "
            size_t endQuote = str.find("\"", startQuote);
            if (endQuote == std::string::npos)
            {
                // We have a start quote but missing the trailing quote "
                GP_ERROR("Compile failed for shader '%s' missing trailing \".", filepath);
                return;
            }

            // jump the head position past the end quote
            headPos = endQuote + 1;
            
            // File path to include and 'stitch' in the value in the quotes to the file path and source it.
            std::string filepathStr = filepath;
            std::string directoryPath = filepathStr.substr(0, filepathStr.rfind('/') + 1);
            size_t len = endQuote - (startQuote);
            std::string includeStr = str.substr(startQuote, len);
            directoryPath.append(includeStr);
            const char* includedSource = FileSystem::readAll(directoryPath.c_str());
            if (includedSource == NULL)
            {
                GP_ERROR("Compile failed for shader '%s' invalid filepath.", filepathStr.c_str());
                return;
            }
            else
            {
                // Valid file so lets attempt to see if we need to append anything to it too (recurse...)
                replaceIncludes(directoryPath.c_str(), includedSource, out);
                SAFE_DELETE_ARRAY(includedSource);
            }
        }
        else
        {
            // Append the remaining
            out.append(str.c_str(), lastPos, tailPos);
        }
    }
}

static void writeShaderToErrorFile(const char* filePath, const char* source)
{
    std::string path = filePath;
    path += ".err";
    std::unique_ptr<Stream> stream(FileSystem::open(path.c_str(), FileSystem::WRITE));
    if (stream.get() != NULL && stream->canWrite())
    {
        stream->write(source, 1, strlen(source));
    }
}

Effect* Effect::createFromSource(const char* vshPath, const char* vshSource, const char* fshPath, const char* fshSource, const char* defines)
{
    GP_ASSERT(vshSource);
    GP_ASSERT(fshSource);

    const unsigned int SHADER_SOURCE_LENGTH = 3;
    const gp_char* shaderSource[SHADER_SOURCE_LENGTH];
    char* infoLog = NULL;
    gp_uint vertexShader;
    gp_uint fragmentShader;
    gp_uint program;
    gp_int length;
    gp_int success;

    // Replace all comma separated definitions with #define prefix and \n suffix
    std::string definesStr = "";
    replaceDefines(defines, definesStr);
    
    shaderSource[0] = definesStr.c_str();
    shaderSource[1] = "\n";
    std::string vshSourceStr = "";
    if (vshPath)
    {
        // Replace the #include "xxxxx.xxx" with the sources that come from file paths
        replaceIncludes(vshPath, vshSource, vshSourceStr);
        if (vshSource && strlen(vshSource) != 0)
            vshSourceStr += "\n";
    }
    shaderSource[2] = vshPath ? vshSourceStr.c_str() :  vshSource;
    GPRHI_ASSERT( vertexShader = GPRHI_CreateShader(GP_RHI_VERTEX_SHADER) );
    GPRHI_ASSERT( GPRHI_ShaderSource(vertexShader, SHADER_SOURCE_LENGTH, shaderSource, NULL) );
    GPRHI_ASSERT( GPRHI_CompileShader(vertexShader) );
    GPRHI_ASSERT( GPRHI_GetShaderiv(vertexShader, GP_RHI_SHADER_GET_COMPILE_STATUS, &success) );
    if (success != GP_TRUE)
    {
        GPRHI_ASSERT( GPRHI_GetShaderiv(vertexShader, GP_RHI_SHADER_GET_INFO_LOG_LENGTH, &length) );
        if (length == 0)
        {
            length = 4096;
        }
        if (length > 0)
        {
            infoLog = new char[length];
            GPRHI_ASSERT( GPRHI_GetShaderInfoLog(vertexShader, length, NULL, infoLog) );
            infoLog[length-1] = '\0';
        }

        // Write out the expanded shader file.
        if (vshPath)
            writeShaderToErrorFile(vshPath, shaderSource[2]);

        GP_ERROR("Compile failed for vertex shader '%s' with error '%s'.", vshPath == NULL ? vshSource : vshPath, infoLog == NULL ? "" : infoLog);
        SAFE_DELETE_ARRAY(infoLog);

        // Clean up.
        GPRHI_ASSERT( GPRHI_DeleteShader(vertexShader) );

        return NULL;
    }

    // Compile the fragment shader.
    std::string fshSourceStr;
    if (fshPath)
    {
        // Replace the #include "xxxxx.xxx" with the sources that come from file paths
        replaceIncludes(fshPath, fshSource, fshSourceStr);
        if (fshSource && strlen(fshSource) != 0)
            fshSourceStr += "\n";
    }
    shaderSource[2] = fshPath ? fshSourceStr.c_str() : fshSource;
    GPRHI_ASSERT( fragmentShader = GPRHI_CreateShader(GP_RHI_PIXEL_SHADER) );
    GPRHI_ASSERT( GPRHI_ShaderSource(fragmentShader, SHADER_SOURCE_LENGTH, shaderSource, NULL) );
    GPRHI_ASSERT( GPRHI_CompileShader(fragmentShader) );
    GPRHI_ASSERT( GPRHI_GetShaderiv(fragmentShader, GP_RHI_SHADER_GET_COMPILE_STATUS, &success) );
    if (success != GP_TRUE)
    {
        GPRHI_ASSERT( GPRHI_GetShaderiv(fragmentShader, GP_RHI_SHADER_GET_INFO_LOG_LENGTH, &length) );
        if (length == 0)
        {
            length = 4096;
        }
        if (length > 0)
        {
            infoLog = new char[length];
            GPRHI_ASSERT( GPRHI_GetShaderInfoLog(fragmentShader, length, NULL, infoLog) );
            infoLog[length-1] = '\0';
        }
        
        // Write out the expanded shader file.
        if (fshPath)
            writeShaderToErrorFile(fshPath, shaderSource[2]);

        GP_ERROR("Compile failed for fragment shader (%s): %s", fshPath == NULL ? fshSource : fshPath, infoLog == NULL ? "" : infoLog);
        SAFE_DELETE_ARRAY(infoLog);

        // Clean up.
        GPRHI_ASSERT( GPRHI_DeleteShader(vertexShader) );
        GPRHI_ASSERT( GPRHI_DeleteShader(fragmentShader) );

        return NULL;
    }

    // Link program.
    GPRHI_ASSERT( program = GPRHI_CreateProgram() );
    GPRHI_ASSERT( GPRHI_AttachShader(program, vertexShader) );
    GPRHI_ASSERT( GPRHI_AttachShader(program, fragmentShader) );
    GPRHI_ASSERT( GPRHI_LinkProgram(program) );
    GPRHI_ASSERT( GPRHI_GetProgramiv(program, GP_RHI_SHADER_GET_LINK_STATUS, &success) );

    // Delete shaders after linking.
    GPRHI_ASSERT( GPRHI_DeleteShader(vertexShader) );
    GPRHI_ASSERT( GPRHI_DeleteShader(fragmentShader) );

    // Check link status.
    if (success != GP_TRUE)
    {
        GPRHI_ASSERT( GPRHI_GetProgramiv(program, GP_RHI_SHADER_GET_INFO_LOG_LENGTH, &length) );
        if (length == 0)
        {
            length = 4096;
        }
        if (length > 0)
        {
            infoLog = new char[length];
            GPRHI_ASSERT( GPRHI_GetProgramInfoLog(program, length, NULL, infoLog) );
            infoLog[length-1] = '\0';
        }
        GP_ERROR("Linking program failed (%s,%s): %s", vshPath == NULL ? "NULL" : vshPath, fshPath == NULL ? "NULL" : fshPath, infoLog == NULL ? "" : infoLog);
        SAFE_DELETE_ARRAY(infoLog);

        // Clean up.
        GPRHI_ASSERT( GPRHI_DeleteProgram(program) );

        return NULL;
    }

    // Create and return the new Effect.
    Effect* effect = new Effect();
    effect->_program = program;

    // Query and store vertex attribute meta-data from the program.
    // NOTE: Rather than using GPRHI_BindAttribLocation to explicitly specify our own
    // preferred attribute locations, we're going to query the locations that were
    // automatically bound by the GPU. While it can sometimes be convenient to use
    // GPRHI_BindAttribLocation, some vendors actually reserve certain attribute indices
    // and therefore using this function can create compatibility issues between
    // different hardware vendors.
    gp_int activeAttributes;
    GPRHI_ASSERT( GPRHI_GetProgramiv(program, GP_RHI_SHADER_GET_ACTIVE_ATTRIBUTES, &activeAttributes) );
    if (activeAttributes > 0)
    {
        GPRHI_ASSERT( GPRHI_GetProgramiv(program, GP_RHI_SHADER_GET_ACTIVE_ATTRIBUTE_MAX_LENGTH, &length) );
        if (length > 0)
        {
            gp_char* attribName = new gp_char[length + 1];
            gp_int attribSize;
            gp_enum attribType;
            gp_int attribLocation;
            for (int i = 0; i < activeAttributes; ++i)
            {
                // Query attribute info.
                GPRHI_ASSERT( GPRHI_GetActiveAttrib(program, i, length, NULL, &attribSize, &attribType, attribName) );
                attribName[length] = '\0';

                // Query the pre-assigned attribute location.
                GPRHI_ASSERT( attribLocation = GPRHI_GetAttribLocation(program, attribName) );

                // Assign the vertex attribute mapping for the effect.
                effect->_vertexAttributes[attribName] = attribLocation;
            }
            SAFE_DELETE_ARRAY(attribName);
        }
    }

    // Query and store uniforms from the program.
    gp_int activeUniforms;
    GPRHI_ASSERT( GPRHI_GetProgramiv(program, GP_RHI_SHADER_GET_ACTIVE_UNIFORMS, &activeUniforms) );
    if (activeUniforms > 0)
    {
        GPRHI_ASSERT( GPRHI_GetProgramiv(program, GP_RHI_SHADER_GET_ACTIVE_UNIFORM_MAX_LENGTH, &length) );
        if (length > 0)
        {
            gp_char* uniformName = new gp_char[length + 1];
            gp_int uniformSize;
            gp_enum uniformType;
            gp_int uniformLocation;
            unsigned int samplerIndex = 0;
            for (int i = 0; i < activeUniforms; ++i)
            {
                // Query uniform info.
                GPRHI_ASSERT( GPRHI_GetActiveUniform(program, i, length, NULL, &uniformSize, &uniformType, uniformName) );
                uniformName[length] = '\0';  // null terminate
                if (length > 3)
                {
                    // If this is an array uniform, strip array indexers off it since GL does not
                    // seem to be consistent across different drivers/implementations in how it returns
                    // array uniforms. On some systems it will return "u_matrixArray", while on others
                    // it will return "u_matrixArray[0]".
                    char* c = strrchr(uniformName, '[');
                    if (c)
                    {
                        *c = '\0';
                    }
                }

                // Query the pre-assigned uniform location.
                GPRHI_ASSERT( uniformLocation = GPRHI_GetUniformLocation(program, uniformName) );

                Uniform* uniform = new Uniform();
                uniform->_effect = effect;
                uniform->_name = uniformName;
                uniform->_location = uniformLocation;
                uniform->_type = uniformType;
                if (uniformType == GP_RHI_UNIFORM_SAMPLER_2D || uniformType == GP_RHI_UNIFORM_SAMPLER_CUBE)
                {
                    uniform->_index = samplerIndex;
                    samplerIndex += uniformSize;
                }
                else
                {
                    uniform->_index = 0;
                }

                effect->_uniforms[uniformName] = uniform;
            }
            SAFE_DELETE_ARRAY(uniformName);
        }
    }

    return effect;
}

const char* Effect::getId() const
{
    return _id.c_str();
}

VertexAttribute Effect::getVertexAttribute(const char* name) const
{
    std::map<std::string, VertexAttribute>::const_iterator itr = _vertexAttributes.find(name);
    return (itr == _vertexAttributes.end() ? -1 : itr->second);
}

Uniform* Effect::getUniform(const char* name) const
{
    std::map<std::string, Uniform*>::const_iterator itr = _uniforms.find(name);

	if (itr != _uniforms.end()) {
		// Return cached uniform variable
		return itr->second;
	}

    gp_int uniformLocation;
    GPRHI_ASSERT( uniformLocation = GPRHI_GetUniformLocation(_program, name) );
    if (uniformLocation > -1)
	{
		// Check for array uniforms ("u_directionalLightColor[0]" -> "u_directionalLightColor")
		char* parentname = new char[strlen(name)+1];
		strcpy(parentname, name);
		if (strtok(parentname, "[") != NULL) {
			std::map<std::string, Uniform*>::const_iterator itr = _uniforms.find(parentname);
			if (itr != _uniforms.end()) {
				Uniform* puniform = itr->second;

				Uniform* uniform = new Uniform();
				uniform->_effect = const_cast<Effect*>(this);
				uniform->_name = name;
				uniform->_location = uniformLocation;
				uniform->_index = 0;
				uniform->_type = puniform->getType();
				_uniforms[name] = uniform;

				SAFE_DELETE_ARRAY(parentname);
				return uniform;
			}
		}
		SAFE_DELETE_ARRAY(parentname);
    }

	// No uniform variable found - return NULL
	return NULL;
}

Uniform* Effect::getUniform(unsigned int index) const
{
    unsigned int i = 0;
    for (std::map<std::string, Uniform*>::const_iterator itr = _uniforms.begin(); itr != _uniforms.end(); ++itr, ++i)
    {
        if (i == index)
        {
            return itr->second;
        }
    }
    return NULL;
}

unsigned int Effect::getUniformCount() const
{
    return (unsigned int)_uniforms.size();
}

void Effect::setValue(Uniform* uniform, float value)
{
    GP_ASSERT(uniform);
    GPRHI_ASSERT( GPRHI_Uniform1f(uniform->_location, value) );
}

void Effect::setValue(Uniform* uniform, const float* values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(values);
    GPRHI_ASSERT( GPRHI_Uniform1fv(uniform->_location, count, values) );
}

void Effect::setValue(Uniform* uniform, int value)
{
    GP_ASSERT(uniform);
    GPRHI_ASSERT( GPRHI_Uniform1i(uniform->_location, value) );
}

void Effect::setValue(Uniform* uniform, const int* values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(values);
    GPRHI_ASSERT( GPRHI_Uniform1iv(uniform->_location, count, values) );
}

void Effect::setValue(Uniform* uniform, const Matrix& value)
{
    GP_ASSERT(uniform);
    GPRHI_ASSERT( GPRHI_UniformMatrix4fv(uniform->_location, 1, GP_FALSE, value.m) );
}

void Effect::setValue(Uniform* uniform, const Matrix* values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(values);
    GPRHI_ASSERT( GPRHI_UniformMatrix4fv(uniform->_location, count, GP_FALSE, (gp_float*)values) );
}

void Effect::setValue(Uniform* uniform, const Vector2& value)
{
    GP_ASSERT(uniform);
    GPRHI_ASSERT( GPRHI_Uniform2f(uniform->_location, value.x, value.y) );
}

void Effect::setValue(Uniform* uniform, const Vector2* values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(values);
    GPRHI_ASSERT( GPRHI_Uniform2fv(uniform->_location, count, (gp_float*)values) );
}

void Effect::setValue(Uniform* uniform, const Vector3& value)
{
    GP_ASSERT(uniform);
    GPRHI_ASSERT( GPRHI_Uniform3f(uniform->_location, value.x, value.y, value.z) );
}

void Effect::setValue(Uniform* uniform, const Vector3* values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(values);
    GPRHI_ASSERT( GPRHI_Uniform3fv(uniform->_location, count, (gp_float*)values) );
}

void Effect::setValue(Uniform* uniform, const Vector4& value)
{
    GP_ASSERT(uniform);
    GPRHI_ASSERT( GPRHI_Uniform4f(uniform->_location, value.x, value.y, value.z, value.w) );
}

void Effect::setValue(Uniform* uniform, const Vector4* values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(values);
    GPRHI_ASSERT( GPRHI_Uniform4fv(uniform->_location, count, (gp_float*)values) );
}

void Effect::setValue(Uniform* uniform, const Texture::Sampler* sampler)
{
    GP_ASSERT(uniform);
    GP_ASSERT(uniform->_type == GP_RHI_UNIFORM_SAMPLER_2D || uniform->_type == GP_RHI_UNIFORM_SAMPLER_CUBE);
    GP_ASSERT(sampler);
    GP_ASSERT((sampler->getTexture()->getType() == Texture::TEXTURE_2D && uniform->_type == GP_RHI_UNIFORM_SAMPLER_2D) || 
        (sampler->getTexture()->getType() == Texture::TEXTURE_CUBE && uniform->_type == GP_RHI_UNIFORM_SAMPLER_CUBE));

    GPRHI_ASSERT( GPRHI_ActiveTexture(GP_RHI_TEXTURE_SLOT_0 + uniform->_index) );

    // Bind the sampler - this binds the texture and applies sampler state
    const_cast<Texture::Sampler*>(sampler)->bind();

    GPRHI_ASSERT( GPRHI_Uniform1i(uniform->_location, uniform->_index) );
}

void Effect::setValue(Uniform* uniform, const Texture::Sampler** values, unsigned int count)
{
    GP_ASSERT(uniform);
    GP_ASSERT(uniform->_type == GP_RHI_UNIFORM_SAMPLER_2D || uniform->_type == GP_RHI_UNIFORM_SAMPLER_CUBE);
    GP_ASSERT(values);

    // Set samplers as active and load texture unit array
    gp_int units[32];
    for (unsigned int i = 0; i < count; ++i)
    {
        GP_ASSERT((const_cast<Texture::Sampler*>(values[i])->getTexture()->getType() == Texture::TEXTURE_2D && uniform->_type == GP_RHI_UNIFORM_SAMPLER_2D) || 
            (const_cast<Texture::Sampler*>(values[i])->getTexture()->getType() == Texture::TEXTURE_CUBE && uniform->_type == GP_RHI_UNIFORM_SAMPLER_CUBE));
        GPRHI_ASSERT( GPRHI_ActiveTexture(GP_RHI_TEXTURE_SLOT_0 + uniform->_index + i) );

        // Bind the sampler - this binds the texture and applies sampler state
        const_cast<Texture::Sampler*>(values[i])->bind();

        units[i] = uniform->_index + i;
    }

    // Pass texture unit array to GL
    GPRHI_ASSERT( GPRHI_Uniform1iv(uniform->_location, count, units) );
}

void Effect::bind()
{
   GPRHI_ASSERT( GPRHI_UseProgram(_program) );

    __currentEffect = this;
}

Effect* Effect::getCurrentEffect()
{
    return __currentEffect;
}

Uniform::Uniform() :
    _location(-1), _type(0), _index(0), _effect(NULL)
{
}

Uniform::~Uniform()
{
    // hidden
}

Effect* Uniform::getEffect() const
{
    return _effect;
}

const char* Uniform::getName() const
{
    return _name.c_str();
}

const gp_enum Uniform::getType() const
{
    return _type;
}

}
