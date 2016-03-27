#include "../../Base.h"
#ifdef USE_VULKAN
#pragma message ("TODO -------------------- not implemented")
gp_enum GPRHI_Viewport(gp_int _x, gp_int _y, gp_sizei _width, gp_sizei _height)
{
	return 0;
}
gp_enum GPRHI_ClearColor(gp_clampf _red, gp_clampf _green, gp_clampf _blue, gp_clampf _alpha)
{
	return 0;
}
gp_enum GPRHI_ClearDepth(gp_clampd _depth)
{
	return 0;
}
gp_enum GPRHI_ClearStencil(gp_int _s)
{
	return 0;
}
gp_enum GPRHI_Clear(gp_bitfield _mask)
{
	return 0;
}
gp_enum GPRHI_DrawElements(gp_enum _mode, gp_sizei _count, gp_enum _type, const gp_void *_indices)
{
	return 0;
}
gp_enum GPRHI_DrawArrays(gp_enum _mode, gp_int _first, gp_sizei _count)
{
	return 0;
}
gp_enum GPRHI_GetIntegerv(gp_enum _cap, gp_int* _value)
{
	return 0;
}
gp_enum GPRHI_GetError()
{
	return 0;
}
#endif 

