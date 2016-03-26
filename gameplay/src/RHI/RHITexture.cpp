#include "../Base.h"

gp_enum GPRHI_DeleteTextures(gp_int _n, gp_uint* _textures)
{
	GL_ASSERT(glDeleteTextures(_n, _textures));
	return 0;
}
gp_enum GPRHI_GenTextures(gp_int _n, gp_uint* _textures)
{
	GL_ASSERT(glGenTextures(_n, _textures));
	return 0;
}
gp_enum GPRHI_BindTexture(gp_enum _target, gp_uint _texture)
{
	GL_ASSERT(glBindTexture(_target, _texture));
	return 0;
}
gp_enum GPRHI_PixelStorei(gp_enum _pname, gp_uint _param)
{
	GL_ASSERT(glPixelStorei(_pname, _param));
	return 0;
}
gp_enum GPRHI_TexParameteri(gp_enum _target, gp_enum _pname, gp_int _param)
{
	GL_ASSERT(glTexParameteri(_target, _pname, _param));
	return 0;
}
gp_enum GPRHI_TexImage2D(gp_enum _target, gp_int _level, gp_int _internalformat, gp_sizei _width, gp_sizei _height, gp_int _border, gp_enum _format, gp_enum _type, const gp_void *_pixels)
{
	GL_ASSERT(glTexImage2D(_target, _level, _internalformat, _width, _height, _border, _format, _type, _pixels));
	return 0;
}
gp_enum GPRHI_TexSubImage2D(gp_enum _target, gp_int _level, gp_int _xoffset, gp_int _yoffset, gp_sizei _width, gp_sizei _height, gp_enum _format, gp_enum _type, const gp_void *_pixels)
{
	GL_ASSERT(glTexSubImage2D(_target, _level, _xoffset, _yoffset, _width, _height, _format, _type, _pixels));
	return 0;
}
gp_enum GPRHI_CompressedTexImage2D(gp_enum _target, gp_int _level, gp_enum _internalformat, gp_sizei _width, gp_sizei _height, gp_int _border, gp_sizei _imageSize, const gp_void *_data)
{
	GL_ASSERT(glCompressedTexImage2D(_target, _level, _internalformat, _width, _height, _border, _imageSize, _data));
	return 0;
}
gp_enum GPRHI_GenerateMipmap(gp_enum _target)
{
	GL_ASSERT(glGenerateMipmap(_target));
	return 0;
}
gp_enum GPRHI_Hint(gp_enum _target, gp_enum _mode)
{
	GL_ASSERT(glHint(_target, _mode));
	return 0;
}
