#pragma once

#ifdef _STATIC
#define MATH_API
#else
#ifdef _USRDLL
#define MATH_API __declspec(dllexport)
#else
#define MATH_API __declspec(dllimport)
#endif
#endif
#ifdef __cplusplus
extern "C"      
{
#endif
	MATH_API int Add(int a, int b);
	MATH_API int Mul(int a, int b);
	MATH_API int Sub(int a, int b);
	MATH_API float Div(int a, int b);
#ifdef __cplusplus
}
#endif