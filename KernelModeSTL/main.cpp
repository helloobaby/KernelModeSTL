#include "./include/stdafx.h"

#include"example.hpp"

void DriverUnload(PDRIVER_OBJECT driverObject);

using std::string;
using std::vector;

#ifdef DBG
extern ULONG memory_alloc;
extern ULONG memory_free;
#endif // DBG


extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driverObject, PUNICODE_STRING registPath)
{
	_CRT_INIT();
	driverObject->DriverUnload = DriverUnload;

	test();

	//leetcode58();




	return STATUS_SUCCESS;
}

void DriverUnload(PDRIVER_OBJECT driverObject) {
	_CRT_UNLOAD();
	//≈–∂œ «∑Ò¥Ê‘⁄memory leak

#ifdef DBG
	if (memory_free != memory_alloc)
	{
		Log("[WARNING]Memory Leaked!\n");
		Log("%d %d", memory_alloc, memory_free);
	}
#endif // DBG

	Log("Driver Exit\n");
}