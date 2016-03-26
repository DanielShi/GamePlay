#include "../Base.h"
gp_enum GPRHI_Enable(gp_enum _cap)
{
	GL_ASSERT(glEnable(_cap));
	return 0;
}
gp_enum GPRHI_Disable(gp_enum _cap)
{
	GL_ASSERT(glDisable(_cap));
	return 0;
}
gp_enum GPRHI_BlendFunc(gp_enum _sfactor, gp_enum _dfactor)
{
	GL_ASSERT(glBlendFunc(_sfactor, _dfactor));
	return 0;
}
gp_enum GPRHI_CullFace(gp_enum _mode)
{
	GL_ASSERT(glCullFace(_mode));
	return 0;
}
gp_enum GPRHI_FrontFace(gp_enum _mode)
{
	GL_ASSERT(glFrontFace(_mode));
	return 0;
}
gp_enum GPRHI_DepthMask(gp_boolean _flag)
{
	GL_ASSERT(glDepthMask(_flag));
	return 0;
}
gp_enum GPRHI_DepthFunc(gp_enum _func)
{
	GL_ASSERT(glDepthFunc(_func));
	return 0;
}
gp_enum GPRHI_StencilMask(gp_uint _mask)
{
	GL_ASSERT(glStencilMask(_mask));
	return 0;
}
gp_enum GPRHI_StencilFunc(gp_enum _func, gp_int _ref, gp_uint _mask)
{
	GL_ASSERT(glStencilFunc(_func, _ref, _mask));
	return 0;
}
gp_enum GPRHI_StencilOp(gp_enum _fail, gp_enum _zfail, gp_enum _zpass)
{
	GL_ASSERT(glStencilOp(_fail, _zfail, _zpass));
	return 0;
}
