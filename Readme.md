#KernelModeSTL

写驱动时可以用的C++STL，原则上追求稳定和开发效率，放弃性能。

new和delete重载为ExAllocatePoolWithQuotaTag，

分配失败自动引发异常。

此项目经过反复排查确保无内存泄露。

使用方法：将include文件夹拷贝到你得项目下，作为重载new和delete，还有全局construct和destroy，

然后你要用比如vector的话，拷贝vector.hpp和.cpp到你的项目下,#include"vector.hpp"即可

在DriverEntry中你必须保证在使用任何容器前调用_CRT_INIT()，这个函数实质上是调用全局构造来初始化全局类。
同理，DriverUnload调用_CRT_UNLOAD()，析构所有全局类。

