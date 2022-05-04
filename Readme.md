#KernelModeSTL

C++ STL for Windows Driver Develop。

使用方法：

将include文件夹拷贝到你的项目下

**Usage example**

https://github.com/helloobaby/Intel-Hv/blob/04a251fba2b6d481a8230297ebd5344c6e51beca/HyperPlatform/service_hook.cpp#L129

https://github.com/helloobaby/Intel-Hv/blob/04a251fba2b6d481a8230297ebd5344c6e51beca/HyperPlatform/service_hook.cpp#L134


TODO (user mode ported to kernel mode) :    
https://github.com/helloobaby/bstree/blob/main/bstree.cpp



2022.5.4  
* windows内核里自带很多数据结构,单双链表\队列\哈希表等,也有接口可以调用,并不需要自己实现,也没必要移植用户层的模板库到内核里 *
