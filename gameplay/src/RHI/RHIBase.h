#ifndef __RHI_BASE_H__
#define __RHI_BASE_H__

typedef unsigned char	gp_ubyte;
typedef int				gp_sizei;
typedef int				gp_int;
typedef unsigned int	gp_uint;
typedef int				gp_enum;
typedef void			gp_void;
typedef ptrdiff_t		gp_sizeiptr;
typedef ptrdiff_t		gp_intptr;
typedef bool			gp_boolean;
typedef char			gp_char;
typedef float			gp_float;
typedef float			gp_clampf;
typedef double			gp_clampd;
typedef unsigned int	gp_bitfield;

#define GP_TRUE			(1)
#define GP_FALSE		(0)
#define GP_NONE			(0)


#ifdef USE_GLES

enum GP_RHI_CLEAR_FLAG {
	GP_RHI_CLEAR_COLOR_BUFFER							= GL_COLOR_BUFFER_BIT,
	GP_RHI_CLEAR_DEPTH_BUFFER							= GL_DEPTH_BUFFER_BIT,
	GP_RHI_CLEAR_STENCIL_BUFFER							= GL_STENCIL_BUFFER_BIT,
};

enum GP_RHI_BUFFER_TYPE {
	GP_RHI_BUFFER_ARRAY									= GL_ARRAY_BUFFER,
	GP_RHI_BUFFER_INDEX									= GL_ELEMENT_ARRAY_BUFFER, 
	GP_RHI_BUFFER_FRAME_BUFFER							= GL_FRAMEBUFFER,
	GP_RHI_BUFFER_RENDER_BUFFER							= GL_RENDERBUFFER,
};
enum GP_RHI_BUFFER_ATTACHMENT {
	GP_RHI_BUFFER_ATTACHMENT_COLOR_0					= GL_COLOR_ATTACHMENT0, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_1 					= GL_COLOR_ATTACHMENT1, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_2 					= GL_COLOR_ATTACHMENT2, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_3 					= GL_COLOR_ATTACHMENT3, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_4 					= GL_COLOR_ATTACHMENT4, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_5 					= GL_COLOR_ATTACHMENT5, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_6 					= GL_COLOR_ATTACHMENT6, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_7 					= GL_COLOR_ATTACHMENT7, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_8 					= GL_COLOR_ATTACHMENT8, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_9 					= GL_COLOR_ATTACHMENT9, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_10					= GL_COLOR_ATTACHMENT10, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_11 					= GL_COLOR_ATTACHMENT11, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_12					= GL_COLOR_ATTACHMENT12, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_13					= GL_COLOR_ATTACHMENT13, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_14					= GL_COLOR_ATTACHMENT14, 
	GP_RHI_BUFFER_ATTACHMENT_COLOR_15					= GL_COLOR_ATTACHMENT15, 
	GP_RHI_BUFFER_ATTACHMENT_DEPTH						= GL_DEPTH_ATTACHMENT, 
	GP_RHI_BUFFER_ATTACHMENT_STENCIL 					= GL_STENCIL_ATTACHMENT,
};

enum GP_RHI_FRAMEBUFFER_STATUS {
	GP_RHI_FRAMEBUFFER_COMPLETE							= GL_FRAMEBUFFER_COMPLETE,
};
enum GP_RHI_BUFFER_ALLOC {
	GP_RHI_BUFFER_DANAMIC								= GL_DYNAMIC_DRAW,
	GP_RHI_BUFFER_STATIC								= GL_STATIC_DRAW,
};

enum GP_RHI_FORMAT {
	//the color format
	GP_RHI_FORMAT_RGB									= GL_RGB,
	GP_RHI_FORMAT_RGBA									= GL_RGBA,
	GP_RHI_FORMAT_ALPHA									= GL_ALPHA,
	GP_RHI_FORMAT_D32F									= GL_DEPTH_COMPONENT32,
	GP_RHI_FORMAT_D24F									= GL_DEPTH_COMPONENT24,
	GP_RHI_FORMAT_D16F									= GL_DEPTH_COMPONENT16,
	GP_RHI_FORMAT_DEPTH									= GL_DEPTH_COMPONENT,
	GP_RHI_FORMAT_D24S8									= GL_DEPTH24_STENCIL8,
	GP_RHI_FORMAT_S8									= GL_STENCIL_INDEX8,
	//the buffer data format
	GP_RHI_FORMAT_UNSIGNED_BYTE							= GL_UNSIGNED_BYTE,
	GP_RHI_FORMAT_UNSIGNED_SHORT						= GL_UNSIGNED_SHORT,
	GP_RHI_FORMAT_UNSIGNED_SHORT_5_6_5					= GL_UNSIGNED_SHORT_5_6_5,
	GP_RHI_FORMAT_UNSIGNED_SHORT_4_4_4_4				= GL_UNSIGNED_SHORT_4_4_4_4,
	GP_RHI_FORMAT_UNSIGNED_SHORT_5_5_5_1				= GL_UNSIGNED_SHORT_5_5_5_1,
	GP_RHI_FORMAT_FLOAT									= GL_FLOAT,
	GP_RHI_FORMAT_UNSIGNED_INT							= GL_UNSIGNED_INT, 
};

enum GP_RHI_TOPOLOGY {
	GP_RHI_TOPOLOGY_TRIANGLES							= GL_TRIANGLES,
	GP_RHI_TOPOLOGY_TRIANGLE_STRIP						= GL_TRIANGLE_STRIP,
	GP_RHI_TOPOLOGY_LINES								= GL_LINES,
	GP_RHI_TOPOLOGY_LINE_STRIP							= GL_LINE_STRIP,
	GP_RHI_TOPOLOGY_LINE_LOOP							= GL_LINE_LOOP,
	GP_RHI_TOPOLOGY_POINTS								= GL_POINTS,
};

enum GP_RHI_TEXTURE_PARAM_NAME {
	GP_RHI_TEXTURE_PARAM_GENERATE_MIPMAP				= GL_GENERATE_MIPMAP,
	GP_RHI_TEXTURE_PARAM_MAG_FILTER						= GL_TEXTURE_MAG_FILTER,
	GP_RHI_TEXTURE_PARAM_MIN_FILTER						= GL_TEXTURE_MIN_FILTER,
	GP_RHI_TEXTURE_PARAM_WRAP_S							= GL_TEXTURE_WRAP_S,
	GP_RHI_TEXTURE_PARAM_WRAP_T							= GL_TEXTURE_WRAP_T,
	GP_RHI_TEXTURE_PARAM_WRAP_R							= GL_TEXTURE_WRAP_R,
	GP_RHI_TEXTURE_PARAM_COMPARE_MODE					= GL_TEXTURE_COMPARE_MODE,
};

enum GP_RHI_TEXTURE_WRAP {
	GP_RHI_TEXTURE_WRAP_REPEAT							= GL_REPEAT,
	GP_RHI_TEXTURE_WRAP_CLAMP_TO_EDGE					= GL_CLAMP_TO_EDGE,
};

enum GP_RHI_TEXTURE_FILTER {
	GP_RHI_TEXTURE_FILTER_NEAREST						= GL_NEAREST,
	GP_RHI_TEXTURE_FILTER_LINEAR						= GL_LINEAR,
	GP_RHI_TEXTURE_FILTER_NEAREST_MIPMAP_NEAREST		= GL_NEAREST_MIPMAP_NEAREST,
	GP_RHI_TEXTURE_FILTER_LINEAR_MIPMAP_NEAREST 		= GL_LINEAR_MIPMAP_NEAREST,          
	GP_RHI_TEXTURE_FILTER_NEAREST_MIPMAP_LINEAR 		= GL_NEAREST_MIPMAP_LINEAR,          
	GP_RHI_TEXTURE_FILTER_LINEAR_MIPMAP_LINEAR 			= GL_LINEAR_MIPMAP_LINEAR,           
};

enum GP_RHI_TEXTURE_TARGET {
	GP_RHI_TEXTURE_TARGET_TEXTURE_2D					= GL_TEXTURE_2D,
	GP_RHI_TEXTURE_TARGET_TEXTURE_CUPE_MAP				= GL_TEXTURE_CUBE_MAP,
	GP_RHI_TEXTURE_TARGET_CUBE_MAP_POSITIVE_X			= GL_TEXTURE_CUBE_MAP_POSITIVE_X,
	GP_RHI_TEXTURE_TARGET_CUBE_MAP_NEGETIVE_X 			= GL_TEXTURE_CUBE_MAP_NEGATIVE_X,
	GP_RHI_TEXTURE_TARGET_CUBE_MAP_POSITIVE_Y 			= GL_TEXTURE_CUBE_MAP_POSITIVE_Y,
	GP_RHI_TEXTURE_TARGET_CUBE_MAP_NEGATIVE_Y			= GL_TEXTURE_CUBE_MAP_NEGATIVE_Y,
	GP_RHI_TEXTURE_TARGET_CUBE_MAP_POSITIVE_Z 			= GL_TEXTURE_CUBE_MAP_POSITIVE_Z,
	GP_RHI_TEXTURE_TARGET_CUBE_MAP_NEGATIVE_Z 			= GL_TEXTURE_CUBE_MAP_NEGATIVE_Z,
};

enum GP_RHI_PIXEL_STORE {
	GP_RHI_PIXEL_STORE_UNPACK_ALIGHMENT					= GL_UNPACK_ALIGNMENT,
};

enum GP_RHI_HINT {
	GP_RHI_HINT_GENERATE_MIPMAP_HINT					= GL_GENERATE_MIPMAP_HINT,
};

enum GP_RHI_HINT_MODE {
	GP_RHI_HINT_MODE_NICEST								= GL_NICEST,
};

enum GP_RHI_SHADER_TYPE {
	GP_RHI_VERTEX_SHADER								= GL_VERTEX_SHADER,
	GP_RHI_PIXEL_SHADER									= GL_FRAGMENT_SHADER,
};

enum GP_RHI_SHADER_GET {
	GP_RHI_SHADER_GET_INFO_LOG_LENGTH					= GL_INFO_LOG_LENGTH,
	GP_RHI_SHADER_GET_COMPILE_STATUS 					= GL_COMPILE_STATUS,
	GP_RHI_SHADER_GET_LINK_STATUS						= GL_LINK_STATUS,
	GP_RHI_SHADER_GET_ACTIVE_ATTRIBUTES					= GL_ACTIVE_ATTRIBUTES,
	GP_RHI_SHADER_GET_ACTIVE_ATTRIBUTE_MAX_LENGTH		= GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,
	GP_RHI_SHADER_GET_ACTIVE_UNIFORMS					= GL_ACTIVE_UNIFORMS,
	GP_RHI_SHADER_GET_ACTIVE_UNIFORM_MAX_LENGTH			= GL_ACTIVE_UNIFORM_MAX_LENGTH,
};

enum GP_RHI_UNIFORM_TYPE {
	GP_RHI_UNIFORM_SAMPLER_2D							= GL_SAMPLER_2D,
	GP_RHI_UNIFORM_SAMPLER_CUBE 						= GL_SAMPLER_CUBE,
};

enum GP_RHI_TEXTURE_SLOT {
	GP_RHI_TEXTURE_SLOT_0								= GL_TEXTURE0, 
	GP_RHI_TEXTURE_SLOT_1								= GL_TEXTURE1, 
	GP_RHI_TEXTURE_SLOT_2								= GL_TEXTURE2, 
	GP_RHI_TEXTURE_SLOT_3								= GL_TEXTURE3, 
	GP_RHI_TEXTURE_SLOT_4								= GL_TEXTURE4, 
	GP_RHI_TEXTURE_SLOT_5								= GL_TEXTURE5, 
	GP_RHI_TEXTURE_SLOT_6								= GL_TEXTURE6, 
	GP_RHI_TEXTURE_SLOT_7								= GL_TEXTURE7, 
	GP_RHI_TEXTURE_SLOT_8								= GL_TEXTURE8, 
	GP_RHI_TEXTURE_SLOT_9								= GL_TEXTURE9, 
	GP_RHI_TEXTURE_SLOT_10								= GL_TEXTURE10,
	GP_RHI_TEXTURE_SLOT_11								= GL_TEXTURE11,
	GP_RHI_TEXTURE_SLOT_12								= GL_TEXTURE12,
	GP_RHI_TEXTURE_SLOT_13								= GL_TEXTURE13,
	GP_RHI_TEXTURE_SLOT_14								= GL_TEXTURE14,
	GP_RHI_TEXTURE_SLOT_15								= GL_TEXTURE15,
	GP_RHI_TEXTURE_SLOT_16								= GL_TEXTURE16,
	GP_RHI_TEXTURE_SLOT_17								= GL_TEXTURE17,
	GP_RHI_TEXTURE_SLOT_18								= GL_TEXTURE18,
	GP_RHI_TEXTURE_SLOT_19								= GL_TEXTURE19,
	GP_RHI_TEXTURE_SLOT_20								= GL_TEXTURE20,
	GP_RHI_TEXTURE_SLOT_21								= GL_TEXTURE21,
	GP_RHI_TEXTURE_SLOT_22								= GL_TEXTURE22,
	GP_RHI_TEXTURE_SLOT_23								= GL_TEXTURE23,
	GP_RHI_TEXTURE_SLOT_24								= GL_TEXTURE24,
	GP_RHI_TEXTURE_SLOT_25								= GL_TEXTURE25,
	GP_RHI_TEXTURE_SLOT_26								= GL_TEXTURE26,
	GP_RHI_TEXTURE_SLOT_27								= GL_TEXTURE27,
	GP_RHI_TEXTURE_SLOT_28								= GL_TEXTURE28,
	GP_RHI_TEXTURE_SLOT_29								= GL_TEXTURE29,
	GP_RHI_TEXTURE_SLOT_30								= GL_TEXTURE30,
	GP_RHI_TEXTURE_SLOT_31								= GL_TEXTURE31,
};


enum GP_RHI_RENDER_STATE {
	GP_RHI_RS_BLEND										= GL_BLEND,
	GP_RHI_RS_CULL_FACE									= GL_CULL_FACE,
	GP_RHI_RS_DEPTH_TEST								= GL_DEPTH_TEST,
	GP_RHI_RS_STENCIL_TEST								= GL_STENCIL_TEST,
};

enum GP_RHI_BLEND_FUNC {
	GP_RHI_BLEND_ONE									= GL_ONE,
	GP_RHI_BLEND_ZERO									= GL_ZERO,
	GP_RHI_BLEND_SRC_COLOR								= GL_SRC_COLOR,
	GP_RHI_BLEND_ONE_MINUS_SRC_COLOR					= GL_ONE_MINUS_SRC_COLOR,
	GP_RHI_BLEND_SRC_ALPHA								= GL_SRC_ALPHA,                      
	GP_RHI_BLEND_ONE_MINUS_SRC_ALPHA					= GL_ONE_MINUS_SRC_ALPHA,
	GP_RHI_BLEND_DST_ALPHA								= GL_DST_ALPHA,            
	GP_RHI_BLEND_ONE_MINUS_DST_ALPHA					= GL_ONE_MINUS_DST_ALPHA,
};

enum GP_RHI_CULL_FACE {
	GP_RHI_CULL_FACE_BACK								= GL_BACK,
	GP_RHI_CULL_FACE_FRONT								= GL_FRONT,
};

enum GP_RHI_FRONT_FACE {
	GP_RHI_FRONT_FACE_CCW								= GL_CCW,
	GP_RHI_FRONT_FACE_CW								= GL_CW,
};

enum GP_RHI_DEPTH_FUNC {
	GP_RHI_DEPTH_FUNC_NEVER								= GL_NEVER,
	GP_RHI_DEPTH_FUNC_LESS 								= GL_LESS,
	GP_RHI_DEPTH_FUNC_EQUAL 							= GL_EQUAL,
	GP_RHI_DEPTH_FUNC_LEQUAL 							= GL_LEQUAL,                        
	GP_RHI_DEPTH_FUNC_GREATER 							= GL_GREATER,                       
	GP_RHI_DEPTH_FUNC_NOTEQUAL 							= GL_NOTEQUAL,                      
	GP_RHI_DEPTH_FUNC_GEQUAL 							= GL_GEQUAL,                        
	GP_RHI_DEPTH_FUNC_ALWAYS 							= GL_ALWAYS,                        
};

#else
#error not implemented
#endif




#define GPRHI_ASSERT(a) a 
//Buffers
gp_enum GPRHI_GenBuffers(gp_sizei _n, gp_uint* _buffers);
gp_enum GPRHI_DeleteBuffers(gp_sizei _n, const gp_uint* _buffers);
gp_enum GPRHI_BindBuffer(gp_enum _target, gp_uint _buffer);
gp_enum GPRHI_BufferData(gp_enum _target, gp_sizeiptr _size, const gp_void* _data, gp_enum _usage);
gp_enum GPRHI_BufferSubData(gp_enum _target, gp_intptr _offset, gp_sizeiptr _size, const gp_void* _data);
//Vertex Buffer
gp_enum GPRHI_GenVertexArrays(gp_sizei _n, gp_uint* _arrays);
gp_enum GPRHI_DeleteVertexArrays(gp_sizei _n, const gp_uint* _arrays);
gp_enum GPRHI_BindVertexArray(gp_uint _array);
gp_enum GPRHI_VertexAttribPointer(gp_uint _index, gp_int _size, gp_enum _type, gp_boolean _normalized, gp_sizei _stride, const gp_void* _pointer);
gp_enum GPRHI_EnableVertexAttribArray(gp_uint _array);
gp_enum GPRHI_DisableVertexAttribArray(gp_uint _array);
//Frame Buffer
gp_enum GPRHI_GenFramebuffers(gp_sizei _n, gp_uint* _framebuffers);
gp_enum GPRHI_DeleteFramebuffers(gp_sizei _n, const gp_uint* _framebuffers);
gp_enum GPRHI_BindFramebuffer(gp_enum _target, gp_uint _framebuffer);
gp_enum GPRHI_FramebufferTexture2D(gp_enum _target, gp_enum _attachment, gp_enum _textarget, gp_uint _texture, gp_int _level);
gp_enum GPRHI_DrawBuffer(gp_enum _target);
gp_enum GPRHI_ReadBuffer(gp_enum _target);
gp_enum GPRHI_DrawBuffers(gp_sizei _n, const gp_enum* _bufs);
gp_enum GPRHI_CheckFramebufferStatus(gp_enum _target);
gp_enum GPRHI_FramebufferRenderbuffer(gp_enum _target, gp_enum _attachment, gp_enum _renderbuffertarget, gp_uint _renderbuffer);
gp_enum GPRHI_ReadPixels(gp_int _x, gp_int _y, gp_sizei _width, gp_sizei _height, gp_enum _format, gp_enum _type, gp_void *_pixels);
//Render Buffer
gp_enum GPRHI_GenRenderbuffers(gp_sizei _n, gp_uint* _renderbuffers);
gp_enum GPRHI_DeleteRenderbuffers(gp_sizei _n, const gp_uint* _renderbuffers);
gp_enum GPRHI_BindRenderbuffer(gp_enum _target, gp_uint _renderbuffer);
gp_enum GPRHI_RenderbufferStorage(gp_enum _target, gp_enum _format, gp_uint _width, gp_uint _height);
//Textures
gp_enum GPRHI_DeleteTextures(gp_int _n, gp_uint* _textures);
gp_enum GPRHI_GenTextures(gp_int _n, gp_uint* _textures);
gp_enum GPRHI_BindTexture(gp_enum _target, gp_uint _texture);
gp_enum GPRHI_PixelStorei(gp_enum _target, gp_uint _texture);
gp_enum GPRHI_TexParameteri(gp_enum _target, gp_enum _pname, gp_int _parame);
gp_enum GPRHI_TexImage2D (gp_enum _target, gp_int _level, gp_int _internalformat, gp_sizei _width, gp_sizei _height, gp_int _border, gp_enum _format, gp_enum _type, const gp_void *_pixels);
gp_enum GPRHI_TexSubImage2D (gp_enum _target, gp_int _level, gp_int _xoffset, gp_int _yoffset, gp_sizei _width, gp_sizei _height, gp_enum _format, gp_enum _type, const gp_void *_pixels);
gp_enum GPRHI_CompressedTexImage2D(gp_enum _target, gp_int _level, gp_enum _internalformat, gp_sizei _width, gp_sizei _height, gp_int _border, gp_sizei _imageSize, const gp_void* _data);
gp_enum GPRHI_GenerateMipmap(gp_enum _target);
gp_enum GPRHI_Hint(gp_enum _target, gp_enum _mode);
//Shaders
gp_uint GPRHI_CreateProgram();
gp_enum GPRHI_LinkProgram(gp_uint _program);
gp_enum GPRHI_UseProgram(gp_uint _program);
gp_enum GPRHI_DeleteProgram(gp_uint _program);
gp_uint GPRHI_CreateShader(gp_enum _type);
gp_enum GPRHI_DeleteShader(gp_uint _shader);
gp_enum GPRHI_ShaderSource(gp_uint _shader, gp_sizei _count, const gp_char** _strings, const gp_int* _lengths);
gp_enum GPRHI_CompileShader(gp_uint _shader);
gp_enum GPRHI_GetShaderiv(gp_uint _shader, gp_enum _pname, gp_int* _param);
gp_enum GPRHI_GetShaderInfoLog(gp_uint _shader, gp_sizei _bufSize, gp_sizei* _length, gp_char* _infoLog);
gp_enum GPRHI_AttachShader(gp_uint _program, gp_uint _shader);
gp_enum GPRHI_Uniform1f(gp_int _location, gp_float _v0);
gp_enum GPRHI_Uniform1fv(gp_int _location, gp_sizei _count, const gp_float* _values);
gp_enum GPRHI_Uniform1i(gp_int _location, gp_int _v0);
gp_enum GPRHI_Uniform1iv(gp_int _location, gp_sizei _count, const gp_int* _values);
gp_enum GPRHI_UniformMatrix4fv(gp_int _location, gp_sizei _count, gp_boolean _transpose, const gp_float* _values);
gp_enum GPRHI_Uniform2f(gp_int _location, gp_float _v0, gp_float _v1);
gp_enum GPRHI_Uniform2fv(gp_int _location, gp_sizei _count, const gp_float* _values);
gp_enum GPRHI_Uniform3f(gp_int _location, gp_float _v0, gp_float _v1, gp_float _v2);
gp_enum GPRHI_Uniform3fv(gp_int _location, gp_sizei _count, const gp_float* _values);
gp_enum GPRHI_Uniform4f(gp_int _location, gp_float _v0, gp_float _v1, gp_float _v2, gp_float _v3);
gp_enum GPRHI_Uniform4fv(gp_int _location, gp_sizei _count, const gp_float* _values);
gp_enum GPRHI_ActiveTexture(gp_enum _texture);
gp_enum GPRHI_GetProgramiv(gp_uint _program, gp_enum _pname, gp_int* _param);
gp_enum GPRHI_GetProgramInfoLog(gp_uint _program, gp_sizei _bufSize, gp_sizei* _length, gp_char* _infoLog);
gp_enum GPRHI_GetActiveAttrib(gp_uint _program, gp_uint _index, gp_sizei _maxLength, gp_sizei* _length, gp_int* _size, gp_enum* _type, gp_char* _name);
gp_int  GPRHI_GetAttribLocation(gp_uint _program, const gp_char* _name);
gp_enum GPRHI_GetActiveUniform(gp_uint _program, gp_uint _index, gp_sizei _maxLength, gp_sizei* _length, gp_int* _size, gp_enum* _type, gp_char* _name);
gp_int  GPRHI_GetUniformLocation(gp_uint _program, const gp_char* _name);
//Render State
gp_enum GPRHI_Enable(gp_enum _cap);
gp_enum GPRHI_Disable(gp_enum _cap);
gp_enum GPRHI_BlendFunc(gp_enum _sfactor, gp_enum _dfactor);
gp_enum GPRHI_CullFace(gp_enum _mode);
gp_enum GPRHI_FrontFace(gp_enum _mode);
gp_enum GPRHI_DepthMask(gp_boolean _flag);
gp_enum GPRHI_DepthFunc(gp_enum _func);
gp_enum GPRHI_StencilMask(gp_uint _mask);
gp_enum GPRHI_StencilFunc(gp_enum _func, gp_int _ref, gp_uint _mask);
gp_enum GPRHI_StencilOp(gp_enum _fail, gp_enum _zfail, gp_enum _zpass);
//Render Command
gp_enum GPRHI_Viewport(gp_int _x, gp_int _y, gp_sizei _width, gp_sizei _height);
gp_enum GPRHI_ClearColor(gp_clampf _red, gp_clampf _green, gp_clampf _blue, gp_clampf _alpha);
gp_enum GPRHI_ClearDepth(gp_clampd _depth);
gp_enum GPRHI_ClearStencil(gp_int _s);
gp_enum GPRHI_Clear(gp_bitfield _mask);
gp_enum GPRHI_DrawElements(gp_enum _mode, gp_sizei _count, gp_enum _type, const gp_void *_indices);
gp_enum GPRHI_DrawArrays(gp_enum _mode, gp_int _first, gp_sizei _count);


#endif
