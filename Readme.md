#KernelModeSTL

C++ STL for Windows Driver Develop��

new��delete����ΪExAllocatePoolWithQuotaTag��

����ʧ���Զ������쳣��

ʹ�÷�����

1.��include�ļ��п����������Ŀ��(��Ϊ����new��delete������ȫ��construct��destroy��,

2.Ȼ����Ҫ�ñ���vector�Ļ�������vector.hpp��vector.cpp�������Ŀ��,#include"vector.hpp"����


ע��:

��DriverEntry������뱣֤��ʹ���κ�����ǰ����_CRT_INIT()���������ʵ�����ǵ���ȫ�ֹ�������ʼ��ȫ���ࡣ

ͬ��DriverUnload����_CRT_UNLOAD()����������ȫ���ࡣ��Ȼ����㲻�ں���Ĺ���������Ļ������Բ����á�


