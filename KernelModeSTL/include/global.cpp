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
	if (p) {	//operator new[] 会用分配的前(size_t)个字节来保存new[]对象的个数
				//编译器在传给void * p的时候会自动帮我们-size_t
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

