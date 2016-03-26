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

#endif
