#KernelModeSTL

写驱动时可以用的C++STL，原则上追求稳定和开发效率，放弃性能。

new和delete重载为ExAllocatePoolWithQuotaTag，

分配失败自动引发异常。

此项目经过反复排查确保无内存泄露。


