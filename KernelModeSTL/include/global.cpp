#include"global.hpp"

#ifdef DBG
ULONG memory_alloc;
ULONG memory_free;
#endif // DBG

extern void __cdecl _RTC_Initialize();
extern void __cdecl _RTC_Terminate();

ULONG Log(const char* format, ...)
{
#ifndef DBG
	return 0;
#endif // DBG

	char buffer[256];

	va_list ap;
	__va_start(&ap, format);
	vsprintf(buffer, format, ap);

	return DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, buffer);
}

void* operator new(size_t size)
{
	void* p = ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
#ifdef DBG
	memory_alloc++;
#endif // DBG

	return p;
}

void* operator new[](size_t size)
{
	void* p = ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');

#ifdef DBG
	memory_alloc++;
#endif // DBG

	return p;
}

void* operator new(size_t, void* _Where)
{
	return (_Where);
}

void operator delete(void* p)
{
	if (p) {
#ifdef DBG
		memory_free++;
#endif // DBG

		ExFreePoolWithTag(p, 'kstl');
	}
}

void operator delete(void* p, size_t size)
{
	size;
	if (p) {
#ifdef DBG
		memory_free++;
#endif // DBG
		ExFreePoolWithTag(p, 'kstl');	}
}

void operator delete[](void* p)
{
	if (p) {	//operator new[] ���÷����ǰ(size_t)���ֽ�������new[]����ĸ���
				//�������ڴ���void * p��ʱ����Զ�������-size_t
#ifdef DBG
		memory_free++;
#endif // DBG
		ExFreePoolWithTag(p, 'kstl');
	}
	
}

void operator delete[](void* p,size_t size)
{
	UNREFERENCED_PARAMETER(size);
	if (p) {
#ifdef DBG
		memory_free++;
#endif // DBG
		ExFreePoolWithTag(p, 'kstl');
	}
	
}

void deallocate(void* p)
{
	if (p) {
#ifdef DBG
		memory_free++;
#endif // DBG
		ExFreePoolWithTag(p, 'kstl');
	}
}

//DriverEntry call this
void _CRT_INIT()
{
	_RTC_Initialize();
}

//DriverUnload call this
void _CRT_UNLOAD()
{
	_RTC_Terminate();
}

