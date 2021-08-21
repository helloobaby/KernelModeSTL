#include "stdafx.h"

#include"example.hpp"

void DriverUnload(PDRIVER_OBJECT driverObject);

using std::string;
using std::vector;

extern ULONG memory_alloc;
extern ULONG memory_free;

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driverObject, PUNICODE_STRING registPath)
{
	_CRT_INIT();
	driverObject->DriverUnload = DriverUnload;

	test();

	//leetcode58();




	//�ж��Ƿ����memory leak
	if (memory_free != memory_alloc)
	{
		Log("[WARNING]Memory Leaked!\n");
		Log("%d %d", memory_alloc, memory_free);
	}
	return STATUS_SUCCESS;
}

void DriverUnload(PDRIVER_OBJECT driverObject) {
	_CRT_UNLOAD();
	Log("Driver Exit\n");
}