#KernelModeSTL

д����ʱ�����õ�C++STL��ԭ����׷���ȶ��Ϳ���Ч�ʣ��������ܡ�

new��delete����ΪExAllocatePoolWithQuotaTag��

����ʧ���Զ������쳣��

����Ŀ���������Ų�ȷ�����ڴ�й¶��

ʹ�÷�������include�ļ��п����������Ŀ�£���Ϊ����new��delete������ȫ��construct��destroy��

Ȼ����Ҫ�ñ���vector�Ļ�������vector.hpp��.cpp�������Ŀ��,#include"vector.hpp"����

��DriverEntry������뱣֤��ʹ���κ�����ǰ����_CRT_INIT()���������ʵ�����ǵ���ȫ�ֹ�������ʼ��ȫ���ࡣ
ͬ��DriverUnload����_CRT_UNLOAD()����������ȫ���ࡣ

