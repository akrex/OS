#include "stdafx.h"
#include "D:\\Projects\\OS\task1\static lib\static lib\Math.h"

MATH_API int Add(int a, int b){
	return a + b;
}

MATH_API int Sub(int a, int b){
	return a - b;
}

MATH_API int Mul(int a, int b){
	return a * b;
}

MATH_API float Div(int a, int b){
	if (b == 0){
		return a;
	}
	return a / b;
}