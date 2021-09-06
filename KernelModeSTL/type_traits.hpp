/*
Copyright (c) 2021-x	 https://github.com/helloobaby/KernelModeSTL
*/


/*

暂时考虑user mode msvc的trpe_traits std::is_pod<T>
因为依赖于编译器的事情，在用户层和内核层并没有什么区别

如果内核中使用出现问题，那么采用本文件中的type_traits

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
	// 要对所有POD类型全特化，后面的先暂时不写
	//
	template <>
	struct is_pod_type<int>
	{
		bool value = true;
	};





}