#pragma once
#include "CppSingleton.hpp"
#include <Windows.h>

enum class ErrType : int {
	NonType = 0
	//else you want
};

class Check_Err : public CppSingleton<Check_Err>
{
private:
	DWORD tls_idx;
public:
	Check_Err();
	~Check_Err();
	int SetErr(ErrType err);
	DWORD GetErr();

	enum {
		TLSALLOC_ERR,
		TLSFREE_ERR
	};
};

