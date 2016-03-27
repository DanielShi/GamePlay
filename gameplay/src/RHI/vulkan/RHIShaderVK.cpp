#include "../../Base.h"
#ifdef USE_VULKAN
#pragma message ("TODO ------------------------ not implemented")
gp_uint GPRHI_CreateProgram()
{
	return 0;
}
gp_enum GPRHI_LinkProgram(gp_uint _program)
{
	return 0;
}
gp_enum GPRHI_UseProgram(gp_uint _program)
{
	return 0;
}
gp_enum GPRHI_DeleteProgram(gp_uint _program)
{
	return 0;
}
gp_uint GPRHI_CreateShader(gp_enum _type)
{
	return 0;
}
gp_enum GPRHI_DeleteShader(gp_uint _shader)
{
	return 0;
}
gp_enum GPRHI_ShaderSource(gp_uint _shader, gp_sizei _count, const gp_char** _strings, const gp_int* _lengths)
{
	return 0;
}
gp_enum GPRHI_CompileShader(gp_uint _shader)
{
	return 0;
}
gp_enum GPRHI_GetShaderiv(gp_uint _shader, gp_enum _pname, gp_int* _param)
{
	return 0;
}
gp_enum GPRHI_GetShaderInfoLog(gp_uint _shader, gp_sizei _bufSize, gp_sizei* _length, gp_char* _infoLog)
{
	return 0;
}
gp_enum GPRHI_AttachShader(gp_uint _program, gp_uint _shader)
{
	return 0;
}
gp_enum GPRHI_Uniform1f(gp_int _location, gp_float _v0)
{
	return 0;
}
gp_enum GPRHI_Uniform1fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	return 0;
}
gp_enum GPRHI_Uniform1i(gp_int _location, gp_int _v0)
{
	return 0;
}
gp_enum GPRHI_Uniform1iv(gp_int _location, gp_sizei _count, const gp_int* _values)
{
	return 0;
}
gp_enum GPRHI_UniformMatrix4fv(gp_int _location, gp_sizei _count, gp_boolean _transpose, const gp_float* _values)
{
	return 0;
}
gp_enum GPRHI_Uniform2f(gp_int _location, gp_float _v0, gp_float _v1)
{
	return 0;
}
gp_enum GPRHI_Uniform2fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	return 0;
}
gp_enum GPRHI_Uniform3f(gp_int _location, gp_float _v0, gp_float _v1, gp_float _v2)
{
	return 0;
}
gp_enum GPRHI_Uniform3fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	return 0;
}
gp_enum GPRHI_Uniform4f(gp_int _location, gp_float _v0, gp_float _v1, gp_float _v2, gp_float _v3)
{
	return 0;
}
gp_enum GPRHI_Uniform4fv(gp_int _location, gp_sizei _count, const gp_float* _values)
{
	return 0;
}
gp_enum GPRHI_ActiveTexture(gp_enum _texture)
{
	return 0;
}
gp_enum GPRHI_GetProgramiv(gp_uint _program, gp_enum _pname, gp_int* _param)
{
	return 0;
}
gp_enum GPRHI_GetProgramInfoLog(gp_uint _program, gp_sizei _bufSize, gp_sizei* _length, gp_char* _infoLog)
{
	return 0;
}
gp_enum GPRHI_GetActiveAttrib(gp_uint _program, gp_uint _index, gp_sizei _maxLength, gp_sizei* _length, gp_int* _size, gp_enum* _type, gp_char* _name)
{
	return 0;
}
gp_int  GPRHI_GetAttribLocation(gp_uint _program, const gp_char* _name)
{
	return 0;
}
gp_enum GPRHI_GetActiveUniform(gp_uint _program, gp_uint _index, gp_sizei _maxLength, gp_sizei* _length, gp_int* _size, gp_enum* _type, gp_char* _name)
{
	return 0;
}
gp_int GPRHI_GetUniformLocation(gp_uint _program, const gp_char* _name)
{
	return 0;
}
#endif