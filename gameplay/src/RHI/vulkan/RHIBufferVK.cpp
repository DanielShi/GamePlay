#include "../../Base.h"
#ifdef USE_VULKAN
#pragma message ("TODO --------------------not implemented")
gp_enum GPRHI_GenBuffers(gp_sizei _n, gp_uint* _buffers)
{
	return 0;
}
gp_enum GPRHI_DeleteBuffers(gp_sizei _n, const gp_uint* _buffers)
{
	return 0;
}
gp_enum GPRHI_BindBuffer(gp_enum _target, gp_uint _buffer)
{
	return 0;
}
gp_enum GPRHI_BufferData(gp_enum _target, gp_sizeiptr _size, const gp_void* _data, gp_enum _usage)
{
	return 0;
}
gp_enum GPRHI_BufferSubData(gp_enum _target, gp_intptr _offset, gp_sizeiptr _size, const gp_void* _data)
{
	return 0;
}
// Vertex Buffer
gp_enum GPRHI_GenVertexArrays(gp_sizei _n, gp_uint* _arrays)
{
	return 0;
}
gp_enum GPRHI_DeleteVertexArrays(gp_sizei _n, const gp_uint* _arrays)
{
	return 0;
}
gp_enum GPRHI_BindVertexArray(gp_uint _array)
{
	return 0;
}
gp_enum GPRHI_VertexAttribPointer(gp_uint _index, gp_int _size, gp_enum _type, gp_boolean _normalized, gp_sizei _stride, const gp_void* _pointer)
{
	return 0;
}
gp_enum GPRHI_EnableVertexAttribArray(gp_uint _array)
{
	return 0;
}

gp_enum GPRHI_DisableVertexAttribArray(gp_uint _array)
{
	return 0;
}

//Frame buffer
gp_enum GPRHI_GenFramebuffers(gp_sizei _n, gp_uint* _framebuffers)
{
	return 0;
}
gp_enum GPRHI_DeleteFramebuffers(gp_sizei _n, const gp_uint* _framebuffers)
{
	return 0;
}
gp_enum GPRHI_BindFramebuffer(gp_enum _target, gp_uint _framebuffer)
{
	return 0;
}
gp_enum GPRHI_FramebufferTexture2D(gp_enum _target, gp_enum _attachment, gp_enum _textarget, gp_uint _texture, gp_int _level)
{
	return 0;
}
gp_enum GPRHI_DrawBuffer(gp_enum _target)
{
	return 0;
}
gp_enum GPRHI_ReadBuffer(gp_enum _target)
{
	return 0;
}
gp_enum GPRHI_DrawBuffers(gp_sizei _n, const gp_enum* _bufs)
{
	return 0;
}
gp_enum GPRHI_CheckFramebufferStatus(gp_enum _target)
{
	return 0;
}
gp_enum GPRHI_FramebufferRenderbuffer(gp_enum _target, gp_enum _attachment, gp_enum _renderbuffertarget, gp_uint _renderbuffer)
{
	return 0;
}
gp_enum GPRHI_ReadPixels(gp_int _x, gp_int _y, gp_sizei _width, gp_sizei _height, gp_enum _format, gp_enum _type, gp_void *_pixels)
{
	return 0;
}
//Render Buffer
gp_enum GPRHI_GenRenderbuffers(gp_sizei _n, gp_uint* _renderbuffers)
{
	return 0;
}
gp_enum GPRHI_DeleteRenderbuffers(gp_sizei _n, const gp_uint* _renderbuffers)
{
	return 0;
}
gp_enum GPRHI_BindRenderbuffer(gp_enum _target, gp_uint _renderbuffer)
{
	return 0;
}
gp_enum GPRHI_RenderbufferStorage(gp_enum _target, gp_enum _format, gp_uint _width, gp_uint _height)
{
	return 0;
}
#endif 