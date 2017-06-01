#include "Check_Err.h"
#include <iostream>

Check_Err::Check_Err()
{
	tls_idx = ::TlsAlloc();
	if (tls_idx == TLS_OUT_OF_INDEXES) throw TLSALLOC_ERR;
	TlsSetValue(tls_idx, new DWORD);
}

Check_Err::~Check_Err()
{
	delete TlsGetValue(tls_idx);
	TlsFree(tls_idx);
}

int Check_Err::SetErr(ErrType err)
{
	DWORD err_to_DW = static_cast<DWORD>(err);
	PDWORD ptr_tls = static_cast<PDWORD>(TlsGetValue(tls_idx));
	*ptr_tls = err_to_DW;
	std::cout << "hehe : " << *ptr_tls << std::endl;
	return 1;
}

DWORD Check_Err::GetErr()
{
	PDWORD ptr = static_cast<PDWORD>(TlsGetValue(tls_idx));
	return *ptr;
}