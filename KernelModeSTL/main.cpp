#include "stdafx.h"

#include"example.hpp"

void DriverUnload(PDRIVER_OBJECT driverObject);

using std::string;
using std::vector;

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT driverObject, PUNICODE_STRING registPath)
{
	driverObject->DriverUnload = DriverUnload;

	//leetcode58();
	vector<string> a;
	a.push_back("123");
	a.push_back("456");
	a.push_back("789");
	a.erase(a.begin()); 
	vector<string>::iterator begin = a.begin();
	while (begin != a.end())
	{
		Log("%s ", begin->c_str());
		begin++;
	}
	Log("size %d ", a.size());


	return STATUS_SUCCESS;
}

void DriverUnload(PDRIVER_OBJECT driverObject) {
	Log("Driver Exit\n");
}