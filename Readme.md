#KernelModeSTL

C++ STL for Windows Driver Develop。

new和delete重载为ExAllocatePoolWithQuotaTag，

分配失败自动引发异常。

使用方法：

1.将include文件夹拷贝到你的项目下(作为重载new和delete，还有全局construct和destroy）,

2.然后你要用比如vector的话，拷贝vector.hpp和vector.cpp到你的项目下,#include"vector.hpp"即可


注意:

在DriverEntry中你必须保证在使用任何容器前调用_CRT_INIT()，这个函数实质上是调用全局构造来初始化全局类。

同理，DriverUnload调用_CRT_UNLOAD()，析构所有全局类。当然如果你不在乎类的构造和析构的话，可以不调用。


