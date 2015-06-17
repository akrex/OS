// TestDll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>

typedef void(*TLSFunct)();

int _tmain(int argc, _TCHAR* argv[])
{
	HMODULE h = LoadLibrary(L"TestDll.dll");
	if (h == 0){
		printf("ERROR load library\n");
		system("pause");
		return 0;
	}
	TLSFunct tls = (TLSFunct)GetProcAddress(h, "TLSTest");
	tls();
	system("pause");
	FreeLibrary(h);
	return 0;
}

