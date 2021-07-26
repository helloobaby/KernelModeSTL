#include "stdafx.h"

#include"example.hpp"

void DriverUnload(PDRIVER_OBJECT driverObject);

using std::string;
using std::vector;

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driverObject, PUNICODE_STRING registPath)
{
	driverObject->DriverUnload = DriverUnload;

	leetcode58();

	return STATUS_SUCCESS;
}

void DriverUnload(PDRIVER_OBJECT driverObject) {
	Log("Driver Exit\n");
}