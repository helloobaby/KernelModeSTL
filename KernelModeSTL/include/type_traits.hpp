/*
Copyright (c) 2021-x	 https://github.com/helloobaby/KernelModeSTL
*/


/*
	std::is_pod������c++20Ҫ������
*/
namespace std
{
	/*
	* �����Ȼ���ã����ǲ�����c++��׼�÷�
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
	// Ҫ��c++����POD����ȫ�ػ�
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
	* ��POD���Ͱ���stringҪƫ�ػ������������hash function
	* �ַ���hash����BKDRHash
	* ����hash����
	*/
	template<>
	struct hash<int>
	{
		
	};




}