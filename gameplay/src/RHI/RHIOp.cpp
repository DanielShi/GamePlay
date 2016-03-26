#include "../Base.h"

gp_enum GPRHI_Viewport(gp_int _x, gp_int _y, gp_sizei _width, gp_sizei _height)
{
	GL_ASSERT(glViewport(_x, _y, _width, _height));
	return 0;
}
gp_enum GPRHI_ClearColor(gp_clampf _red, gp_clampf _green, gp_clampf _blue, gp_clampf _alpha)
{
	GL_ASSERT(glClearColor(_red, _green, _blue, _alpha));
	return 0;
}
gp_enum GPRHI_ClearDepth(gp_clampd _depth)
{
	GL_ASSERT(glClearDepth(_depth));
	return 0;
}
gp_enum GPRHI_ClearStencil(gp_int _s)
{
	GL_ASSERT(glClearStencil(_s));
	return 0;
}
gp_enum GPRHI_Clear(gp_bitfield _mask)
{
	GL_ASSERT(glClear(_mask));
	return 0;
}
gp_enum GPRHI_DrawElements(gp_enum _mode, gp_sizei _count, gp_enum _type, const gp_void *_indices)
{
	GL_ASSERT(glDrawElements(_mode, _count, _type, _indices));
	return 0;
}
gp_enum GPRHI_DrawArrays(gp_enum _mode, gp_int _first, gp_sizei _count)
{
	GL_ASSERT(glDrawArrays(_mode, _first, _count));
	return 0;
}
gp_enum GPRHI_GetIntegerv(gp_enum _cap, gp_int* _value)
{
	GL_ASSERT(glGetIntegerv(_cap, _value));
	return 0;
}
gp_enum GPRHI_GetError()
{
	return glGetError();
}


