#include "../Base.h"
gp_uint GPRHI_CreateProgram()
{
	gp_uint res = 0;
	GL_ASSERT(res = glCreateProgram());
	return res;
}
gp_enum GPRHI_LinkProgram(gp_uint _program)
{
	GL_ASSERT(glLinkProgram(_program));
	return 0;
}
gp_enum GPRHI_UseProgram(gp_uint _program)
{
	GL_ASSERT(glUseProgram(_program));
	return 0;
}
gp_enum GPRHI_DeleteProgram(gp_uint _program)
{
	GL_ASSERT(glDeleteProgram(_program));
	return 0;
}
gp_uint GPRHI_CreateShader(gp_enum _type)
{
	gp_uint res = 0;
	GL_ASSERT(res = glCreateShader(_type));
	return res;
}
gp_enum GPRHI_DeleteShader(gp_uint _shader)
{
	GL_ASSERT(glDeleteShader(_shader));
	return 0;
}
gp_enum GPRHI_ShaderSource(gp_uint _shader, gp_sizei _count, const gp_char** _strings, const gp_int* _lengths)
{
	GL_ASSERT(glShaderSource(_shader, _count, _strings, _lengths));
	return 0;
}
gp_enum GPRHI_CompileShader(gp_uint _shader)
{
	GL_ASSERT(glCompileShader(_shader));
	return 0;
}
gp_enum GPRHI_GetShaderiv(gp_uint _shader, gp_enum _pname, gp_int* _param)
{
	GL_ASSERT(glGetShaderiv(_shader, _pname, _param));
	return 0;
}
gp_enum GPRHI_GetShaderInfoLog(gp_uint _shader, gp_sizei _bufSize, gp_sizei* _length, gp_char* _infoLog)
{
	GL_ASSERT(glGetShaderInfoLog(_shader, _bufSize, _length, _infoLog));
	return 0;
}
gp_enum GPRHI_AttachShader(gp_uint _program, gp_uint _shader)
{
	GL_ASSERT(glAttachShader(_program, _shader));
	return 0;
}
gp_enum GPRHI_Uniform1f(gp_int _location, gp_float _v0)
{
	GL_ASSERT(glUniform1f(_location, _v0));
	return 0;
}
gp_enum GPRHI_Uniform1fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	GL_ASSERT(glUniform1fv(_location, _count, _values));
	return 0;
}
gp_enum GPRHI_Uniform1i(gp_int _location, gp_int _v0)
{
	GL_ASSERT(glUniform1i(_location,_v0));
	return 0;
}
gp_enum GPRHI_Uniform1iv(gp_int _location, gp_sizei _count, const gp_int* _values)
{
	GL_ASSERT(glUniform1iv(_location, _count, _values));
	return 0;
}
gp_enum GPRHI_UniformMatrix4fv(gp_int _location, gp_sizei _count, gp_boolean _transpose, const gp_float* _values)
{
	GL_ASSERT(glUniformMatrix4fv(_location, _count, _transpose, _values));
	return 0;
}
gp_enum GPRHI_Uniform2f(gp_int _location, gp_float _v0, gp_float _v1)
{
	GL_ASSERT(glUniform2f(_location,_v0,_v1));
	return 0;
}
gp_enum GPRHI_Uniform2fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	GL_ASSERT(glUniform2fv(_location,_count,_values));
	return 0;
}
gp_enum GPRHI_Uniform3f(gp_int _location, gp_float _v0, gp_float _v1, gp_float _v2)
{
	GL_ASSERT(glUniform3f(_location,_v0, _v1, _v2));
	return 0;
}
gp_enum GPRHI_Uniform3fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	GL_ASSERT(glUniform3fv(_location,_count, _values));
	return 0;
}
gp_enum GPRHI_Uniform4f(gp_int _location, gp_float _v0, gp_float _v1, gp_float _v2, gp_float _v3)
{
	GL_ASSERT(glUniform4f(_location,_v0, _v1, _v2,_v3));
	return 0;
}
gp_enum GPRHI_Uniform4fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	GL_ASSERT(glUniform4fv(_location,_count, _values));
	return 0;
}
gp_enum GPRHI_ActiveTexture(gp_enum _texture)
{
	GL_ASSERT(glActiveTexture(_texture));
	return 0;
}
gp_enum GPRHI_GetProgramiv(gp_uint _program, gp_enum _pname, gp_int* _param)
{
	GL_ASSERT(glGetProgramiv(_program, _pname, _param));
	return 0;
}
gp_enum GPRHI_GetProgramInfoLog(gp_uint _program, gp_sizei _bufSize, gp_sizei* _length, gp_char* _infoLog)
{
	GL_ASSERT(glGetProgramInfoLog(_program, _bufSize, _length, _infoLog));
	return 0;
}
gp_enum GPRHI_GetActiveAttrib(gp_uint _program, gp_uint _index, gp_sizei _maxLength, gp_sizei* _length, gp_int* _size, gp_enum* _type, gp_char* _name)
{
	GL_ASSERT(glGetActiveAttrib(_program, _index, _maxLength, _length, _size, (GLenum*)_type, _name));
	return 0;
}
gp_int  GPRHI_GetAttribLocation(gp_uint _program, const gp_char* _name)
{
	gp_int res = 0;
	GL_ASSERT(res = glGetAttribLocation(_program, _name));
	return res;
}
gp_enum GPRHI_GetActiveUniform(gp_uint _program, gp_uint _index, gp_sizei _maxLength, gp_sizei* _length, gp_int* _size, gp_enum* _type, gp_char* _name)
{
	GL_ASSERT(glGetActiveUniform(_program, _index, _maxLength, _length, _size, (GLenum*)_type, _name));
	return 0;
}
gp_int GPRHI_GetUniformLocation(gp_uint _program, const gp_char* _name)
{
	gp_int res = 0;
	GL_ASSERT(res = glGetUniformLocation(_program, _name));
	return res;
}
