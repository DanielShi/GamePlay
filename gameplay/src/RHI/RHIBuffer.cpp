#include "../Base.h"

#error what the fuck 

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

