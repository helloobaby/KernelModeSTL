#include"global.hpp"

ULONG Log(const char* format, ...)
{
	char buffer[256];

	va_list ap;
	__va_start(&ap, format);
	vsprintf(buffer, format, ap);

	return DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, buffer);
}

void* operator new(size_t size)
{
#ifndef DBG
	return ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
#endif // !1
	void* p = ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
	Log("Alloc at %p Size is %p\n", p, size);
	return p;
}

void* operator new[](size_t size)
{
#ifndef DBG
	return ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
#endif // !1
	void* p = ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
	Log("Alloc at %p Size is %p\n", p, size);
	return p;
}

void* operator new(size_t, void* _Where)
{
	return (_Where);
}

void operator delete(void* p)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG
	
	if (p) {
		ExFreePoolWithTag(p, 'kstl');
		Log("Free at %p\n", p);
	}
}

void operator delete(void* p, size_t size)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {
		ExFreePoolWithTag(p, 'kstl');
		Log("Free at %p\n", p);
	}
}

void operator delete[](void* p)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {	//operator new[] 会多分配8个字节来保存new[]对象的个数
		ExFreePoolWithTag((void*)((ULONG_PTR)p - 8), 'kstl');
		Log("Free at %p\n", p);
	}
	
}

void operator delete[](void* p,size_t size)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {
		ExFreePoolWithTag(p, 'kstl');
		Log("Free at %p\n", p);
	}
	
}






