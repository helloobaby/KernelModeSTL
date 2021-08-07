#include"global.hpp"

#ifdef DBG
ULONG memory_alloc;
ULONG memory_free;
#endif // DBG


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
	memory_alloc++;
	return p;
}

void* operator new[](size_t size)
{
#ifndef DBG
	return ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
#endif // !1
	void* p = ExAllocatePoolWithQuotaTag(NonPagedPool, size, 'ltsk');
	memory_alloc++;
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
		memory_free++;
		ExFreePoolWithTag(p, 'kstl');
	}
}

void operator delete(void* p, size_t size)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {
		memory_free++;
		ExFreePoolWithTag(p, 'kstl');	}
}

void operator delete[](void* p)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {	//operator new[] 会用分配的前(size_t)个字节来保存new[]对象的个数
				//编译器在传给void * p的时候会自动帮我们-size_t
		memory_free++;
		ExFreePoolWithTag((void*)((ULONG_PTR)p), 'kstl');
	}
	
}

void operator delete[](void* p,size_t size)
{
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {
		memory_free++;
		ExFreePoolWithTag(p, 'kstl');
	}
	
}

void deallocate(void* p)
{
	//这个全局函数存在的意义仅仅是释放内存，而不调用析构函数
#ifndef DBG
	if (p)
		ExFreePoolWithTag(p, 'kstl');
#endif // !DBG

	if (p) {
		memory_free++;
		ExFreePoolWithTag(p, 'kstl');
	}
}






