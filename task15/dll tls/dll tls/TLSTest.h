#include "stdafx.h"

#ifdef _USRDLL
#define TLS_API __declspec(dllexport)
#else
#define TLS_API __declspec(dllimport)
#endif
TLS_API void TLSTest();