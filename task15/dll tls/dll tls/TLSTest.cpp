#include "stdafx.h"
#include "TLSTest.h"
#include <iostream>
#include <Windows.h>

DWORD tls_i;
DWORD tls_counter;

DWORD WINAPI TestFunc(LPVOID lpParam){
	TlsSetValue(tls_i, lpParam);
	TlsSetValue(tls_counter, 0);
	int id = (int)TlsGetValue(tls_i);
	for (int i = 0; i < 10; i++){
		int count = (int)TlsGetValue(tls_counter);
		std::cout << "ID = " << id <<"count "<<count<<std::endl;
		TlsSetValue(tls_counter, (LPVOID)++count);
		Sleep(100);
	}
	return 0;
}

TLS_API void TLSTest(){
	tls_i = TlsAlloc();
	tls_counter = TlsAlloc();
	for (int i = 0; i < 3; i++){
		CreateThread(NULL, 0, TestFunc, (LPVOID)i, 0, NULL);
		Sleep(50);
	}
	TlsFree(tls_i);
	TlsFree(tls_counter);
}