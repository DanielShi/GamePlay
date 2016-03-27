#include "../../Base.h"
#ifdef USE_VULKAN
gp_enum GPRHI_DeleteTextures(gp_int _n, gp_uint* _textures)
{
#pragma message ("TODO ---------------- not implemented")
	return 0;
}
gp_enum GPRHI_GenTextures(gp_int _n, gp_uint* _textures)
{
	return 0;
}
gp_enum GPRHI_BindTexture(gp_enum _target, gp_uint _texture)
{
	return 0;
}
gp_enum GPRHI_PixelStorei(gp_enum _pname, gp_uint _param)
{
	return 0;
}
gp_enum GPRHI_TexParameteri(gp_enum _target, gp_enum _pname, gp_int _param)
{
	return 0;
}
gp_enum GPRHI_TexImage2D(gp_enum _target, gp_int _level, gp_int _internalformat, gp_sizei _width, gp_sizei _height, gp_int _border, gp_enum _format, gp_enum _type, const gp_void *_pixels)
{
	return 0;
}
gp_enum GPRHI_TexSubImage2D(gp_enum _target, gp_int _level, gp_int _xoffset, gp_int _yoffset, gp_sizei _width, gp_sizei _height, gp_enum _format, gp_enum _type, const gp_void *_pixels)
{
	return 0;
}
gp_enum GPRHI_CompressedTexImage2D(gp_enum _target, gp_int _level, gp_enum _internalformat, gp_sizei _width, gp_sizei _height, gp_int _border, gp_sizei _imageSize, const gp_void *_data)
{
	return 0;
}
gp_enum GPRHI_GenerateMipmap(gp_enum _target)
{
	return 0;
}
gp_enum GPRHI_Hint(gp_enum _target, gp_enum _mode)
{
	return 0;
}
gp_boolean GPRHI_IsTexture(gp_uint _texture)
{
	return 0;
}
#endif 
