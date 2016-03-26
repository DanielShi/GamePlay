#include "../Base.h"

gp_enum GPRHI_GenBuffers(gp_sizei _n, gp_uint* _buffers)
{
	GL_ASSERT(glGenBuffers(_n, _buffers));
	return 0;
}
gp_enum GPRHI_DeleteBuffers(gp_sizei _n, const gp_uint* _buffers)
{
	GL_ASSERT(glDeleteBuffers(_n, _buffers));
	return 0;
}
gp_enum GPRHI_BindBuffer(gp_enum _target, gp_uint _buffer)
{
	GL_ASSERT(glBindBuffer(_target, _buffer));
	return 0;
}
gp_enum GPRHI_BufferData(gp_enum _target, gp_sizeiptr _size, const gp_void* _data, gp_enum _usage)
{
	GL_ASSERT(glBufferData(_target, _size, _data, _usage));
	return 0;
}
gp_enum GPRHI_BufferSubData(gp_enum _target, gp_intptr _offset, gp_sizeiptr _size, const gp_void* _data)
{
	GL_ASSERT(glBufferSubData(_target, _offset, _size, _data));
	return 0;
}
// Vertex Buffer
gp_enum GPRHI_GenVertexArrays(gp_sizei _n, gp_uint* _arrays)
{
	GL_ASSERT(glGenVertexArrays(_n, _arrays));
	return 0;
}
gp_enum GPRHI_DeleteVertexArrays(gp_sizei _n, const gp_uint* _arrays)
{
	GL_ASSERT(glDeleteVertexArrays(_n, _arrays));
	return 0;
}
gp_enum GPRHI_BindVertexArray(gp_uint _array)
{
	GL_ASSERT(glBindVertexArray(_array));
	return 0;
}
gp_enum GPRHI_VertexAttribPointer(gp_uint _index, gp_int _size, gp_enum _type, gp_boolean _normalized, gp_sizei _stride, const gp_void* _pointer)
{
	GL_ASSERT(glVertexAttribPointer(_index, _size, _type, _normalized, _stride, _pointer));
	return 0;
}
gp_enum GPRHI_EnableVertexAttribArray(gp_uint _array)
{
	GL_ASSERT(glEnableVertexAttribArray(_array));
	return 0;
}

gp_enum GPRHI_DisableVertexAttribArray(gp_uint _array)
{
	GL_ASSERT(glDisableVertexAttribArray(_array));
	return 0;
}

//Frame buffer
gp_enum GPRHI_GenFramebuffers(gp_sizei _n, gp_uint* _framebuffers)
{
	GL_ASSERT(glGenFramebuffers(_n, _framebuffers));
	return 0;
}
gp_enum GPRHI_DeleteFramebuffers(gp_sizei _n, const gp_uint* _framebuffers)
{
	GL_ASSERT(glDeleteFramebuffers(_n, _framebuffers));
	return 0;
}
gp_enum GPRHI_BindFramebuffer(gp_enum _target, gp_uint _framebuffer)
{
	GL_ASSERT(glBindFramebuffer(_target, _framebuffer));
	return 0;
}
gp_enum GPRHI_FramebufferTexture2D(gp_enum _target, gp_enum _attachment, gp_enum _textarget, gp_uint _texture, gp_int _level)
{
	GL_ASSERT(glFramebufferTexture2D(_target, _attachment, _textarget, _texture, _level));
	return 0;
}
gp_enum GPRHI_DrawBuffer(gp_enum _target)
{
	GL_ASSERT(glDrawBuffer(_target));
	return 0;
}
gp_enum GPRHI_ReadBuffer(gp_enum _target)
{
	GL_ASSERT(glReadBuffer(_target));
	return 0;
}
gp_enum GPRHI_DrawBuffers(gp_sizei _n, const gp_enum* _bufs)
{
#if defined(GL_ES_VERSION_3_0) && GL_ES_VERSION_3_0
	GL_ASSERT(glDrawBuffers(_n, _bufs));
#endif
	return 0;
}
gp_enum GPRHI_CheckFramebufferStatus(gp_enum _target)
{
	return glCheckFramebufferStatus(_target);
}
gp_enum GPRHI_FramebufferRenderbuffer(gp_enum _target, gp_enum _attachment, gp_enum _renderbuffertarget, gp_uint _renderbuffer)
{
	GL_ASSERT(glFramebufferRenderbuffer(_target, _attachment, _renderbuffertarget, _renderbuffer));
	return 0;
}
gp_enum GPRHI_ReadPixels(gp_int _x, gp_int _y, gp_sizei _width, gp_sizei _height, gp_enum _format, gp_enum _type, gp_void *_pixels)
{
	GL_ASSERT(glReadPixels(_x, _y, _width, _height, _format, _type, _pixels));
	return 0;
}
//Render Buffer
gp_enum GPRHI_GenRenderbuffers(gp_sizei _n, gp_uint* _renderbuffers)
{
	GL_ASSERT(glGenRenderbuffers(_n, _renderbuffers));
	return 0;
}
gp_enum GPRHI_DeleteRenderbuffers(gp_sizei _n, const gp_uint* _renderbuffers)
{
	GL_ASSERT(glDeleteRenderbuffers(_n, _renderbuffers));
	return 0;
}
gp_enum GPRHI_BindRenderbuffer(gp_enum _target, gp_uint _renderbuffer)
{
	GL_ASSERT(glBindRenderbuffer(_target, _renderbuffer));
	return 0;
}
gp_enum GPRHI_RenderbufferStorage(gp_enum _target, gp_enum _format, gp_uint _width, gp_uint _height)
{
	GL_ASSERT(glRenderbufferStorage(_target, _format, _width, _height));
	return 0;
}
