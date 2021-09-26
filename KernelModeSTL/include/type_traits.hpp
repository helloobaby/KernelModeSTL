/*
Copyright (c) 2021-x	 https://github.com/helloobaby/KernelModeSTL
*/


/*
	std::is_pod好像在c++20要被弃用
*/
namespace std
{
	/*
	* 这个虽然能用，但是不满足c++标准用法
	template <typename T>
	constexpr bool is_pod()
	{
		return is_pod_type<T>::value;
	}
	*/


	template <typename T>
	struct is_pod
	{
		static const bool value = is_pod_type<T>::value;
		constexpr bool operator()()
		{
			return value;
		}
	};

	template <typename T>
	struct is_pod_type
	{
		static const bool value = false;
	};

	//
	// 要对c++所有POD类型全特化
	//


	template <>
	struct is_pod_type<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<signed char>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<unsigned short>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<unsigned int>
	{
		static const bool value = true;
	};


	template <>
	struct is_pod_type<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<unsigned long>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<float>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<double>
	{
		static const bool value = true;
	};

	template <>
	struct is_pod_type<long double>
	{
		static const bool value = true;
	};

	template<typename T>
	struct is_pod_type<T*>
	{
		static const bool value = true;
	};

	//
	//https://en.cppreference.com/w/cpp/utility/hash
	//
	template<typename _Kty>
	struct hash
	{
		hash() = delete;
	};

	/**
	* 对POD类型包括string要偏特化，并合理设计hash function
	* 字符串hash采用BKDRHash
	* 整数hash采用
	*/
	template<>
	struct hash<int>
	{
		
	};




}