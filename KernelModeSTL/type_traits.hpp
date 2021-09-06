/*
Copyright (c) 2021-x	 https://github.com/helloobaby/KernelModeSTL
*/


/*

��ʱ����user mode msvc��trpe_traits std::is_pod<T>
��Ϊ�����ڱ����������飬���û�����ں˲㲢û��ʲô����

����ں���ʹ�ó������⣬��ô���ñ��ļ��е�type_traits

*/
namespace trial
{

	template <typename T>
	constexpr bool is_pod()
	{
		return is_pod_type<T>::value;
	}

	template <typename T>
	struct is_pod_type
	{
		bool value = false;
	};

	//
	// Ҫ������POD����ȫ�ػ������������ʱ��д
	//
	template <>
	struct is_pod_type<int>
	{
		bool value = true;
	};





}