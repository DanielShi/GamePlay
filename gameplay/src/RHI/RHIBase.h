#ifndef __RHI_BASE_H__
#define __RHI_BASE_H__

typedef unsigned char	gp_ubyte;
typedef int				gp_sizei;
typedef int				gp_int;
typedef unsigned int	gp_uint;
typedef int				gp_enum;
typedef void			gp_void;

#define GP_TRUE			(1)
#define GP_FALSE		(0)
#define GP_NONE			(0)


#ifdef USE_GLES
enum GP_RHI_FORMAT {
	//the color format
	GP_RHI_FORMAT_RGB									= GL_RGB,
	GP_RHI_FORMAT_RGBA									= GL_RGBA,
	GP_RHI_FORMAT_ALPHA									= GL_ALPHA,
	GP_RHI_FORMAT_D32F									= GL_DEPTH_COMPONENT32,
	GP_RHI_FORMAT_DEPTH									= GL_DEPTH_COMPONENT,
	//the buffer data format
	GP_RHI_FORMAT_UNSIGNED_BYTE							= GL_UNSIGNED_BYTE,
	GP_RHI_FORMAT_UNSIGNED_SHORT_5_6_5					= GL_UNSIGNED_SHORT_5_6_5,
	GP_RHI_FORMAT_UNSIGNED_SHORT_4_4_4_4				= GL_UNSIGNED_SHORT_4_4_4_4,
	GP_RHI_FORMAT_UNSIGNED_SHORT_5_5_5_1				= GL_UNSIGNED_SHORT_5_5_5_1,
	GP_RHI_FORMAT_FLOAT									= GL_FLOAT,
	GP_RHI_FORMAT_UNSIGNED_INT							= GL_UNSIGNED_INT, 
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

enum GP_RHI_TEXTURE_PARAM_VALUE {
	GP_RHI_TEXTURE_PARAM_VALUE_NEAREST					= GL_NEAREST,
	GP_RHI_TEXTURE_PARAM_VALUE_LINEAR					= GL_LINEAR,
	GP_RHI_TEXTURE_PARAM_VALUE_CLAMP_TO_EDGE			= GL_CLAMP_TO_EDGE,
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
