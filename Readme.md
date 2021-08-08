#KernelModeSTL

写驱动时可以用的C++STL，原则上追求稳定和开发效率，放弃性能。

new和delete重载为ExAllocatePoolWithQuotaTag，

分配失败自动引发异常。

此项目经过反复排查确保无内存泄露。

使用方法：将include文件夹拷贝到你得项目下，作为重载new和delete，还有全局construct和destroy，

然后你要用比如vector的话，拷贝vector.hpp和.cpp到你的项目下,#include"vector.hpp"即可


