/*
Copyright (c) 2021-x	 https://github.com/helloobaby/KernelModeSTL
*/

#pragma once
#include"include/global.hpp"
#include"vector.hpp"

using std::vector;

namespace std
{

	template <typename value>
	struct _hashtable_node
	{
		//��Ϊֻ����һ���ڵ��ָ��
		//�Դ˷�װ�ĵ�����ֻ֧��ǰ����������֧�ֺ��ˣ�Ҳû�����������
		_hashtable_node* next;
		value val;
	};

	template<class value,
		class key,
		class HashFcn >//Ӧ���ṩĬ�ϵ�hash����
		class hashtable
	{

		using node = _hashtable_node<value>;
		using size_type = size_t;

	private:
		//���buckets̫�٣��ᵼ�¹ҽ�����̫����java��jdk����������ת��Ϊ�����
		vector<node*> buckets;
	public:
		void initialize_buckets(size_type n)
		{
			auto next_size = [n]() {
				//���ش���n���������
			};
		}

		hashtable(size_type n)
		{
			buckets.resize(0);
		}
		
	};

}