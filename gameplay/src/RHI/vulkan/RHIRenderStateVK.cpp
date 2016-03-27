#include "../../Base.h"
#ifdef USE_VULKAN
#pragma message ("TODO ---------------- not implemented")
gp_enum GPRHI_Enable(gp_enum _cap)
{
	return 0;
}
gp_enum GPRHI_Disable(gp_enum _cap)
{
	return 0;
}
gp_enum GPRHI_BlendFunc(gp_enum _sfactor, gp_enum _dfactor)
{
	return 0;
}
gp_enum GPRHI_CullFace(gp_enum _mode)
{
	return 0;
}
gp_enum GPRHI_FrontFace(gp_enum _mode)
{
	return 0;
}
gp_enum GPRHI_DepthMask(gp_boolean _flag)
{
	return 0;
}
gp_enum GPRHI_DepthFunc(gp_enum _func)
{
	return 0;
}
gp_enum GPRHI_StencilMask(gp_uint _mask)
{
	return 0;
}
gp_enum GPRHI_StencilFunc(gp_enum _func, gp_int _ref, gp_uint _mask)
{
	return 0;
}
gp_enum GPRHI_StencilOp(gp_enum _fail, gp_enum _zfail, gp_enum _zpass)
{
	return 0;
}
#endif