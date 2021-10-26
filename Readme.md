#KernelModeSTL

C++ STL for Windows Driver Develop。

new和delete重载为ExAllocatePoolWithQuotaTag，

分配失败自动引发异常。

使用方法：

将include文件夹拷贝到你的项目下

注意:

在DriverEntry中你必须保证在使用任何容器前调用_CRT_INIT()，这个函数实质上是调用全局构造来初始化全局类。

同理，DriverUnload调用_CRT_UNLOAD()，析构所有全局类。当然如果你不在乎类的构造和析构的话，可以不调用。


例子(Example)：

![Image Text](https://github.com/helloobaby/KernelModeSTL/blob/master/show2.png)

![Image Text](https://github.com/helloobaby/KernelModeSTL/blob/master/show1.png)


**Usage example**

https://github.com/helloobaby/Intel-Hv/blob/04a251fba2b6d481a8230297ebd5344c6e51beca/HyperPlatform/service_hook.cpp#L129

https://github.com/helloobaby/Intel-Hv/blob/04a251fba2b6d481a8230297ebd5344c6e51beca/HyperPlatform/service_hook.cpp#L134
