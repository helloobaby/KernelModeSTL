/*
Copyright (c) 2021-x	 https://github.com/helloobaby/KernelModeSTL
*/

#pragma once
#include"include/global.hpp"
#include"vector.hpp"

using std::vector;


namespace std
{
	inline int prime_list_size = 20;
	inline unsigned long prime_list[]
	{
		/**
		* table sizeһ����ҪΪ������
		* ��ֹ����������� 60 % table size ��80 % table size �� 100 % table size
		* ����õ�indexΪ0�������
		*/
		53,97,193,389,769,
		1543,3079,6151,12289,24593,
		49157,98317,196613,393241,786433,
		1572869,3145739,6291469,12582917,25165843
	};

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
			class HashFcn>//Ӧ���ṩĬ�ϵ�hash����
	class hashtable
	{
		using node = _hashtable_node<value>;
		using size_type = size_t;

	private:
		/**
		* 
		* 
		* buckets[0]
		*		 [1]
		*		 [2]
		*		 [3]
		*		 ...
		*		 ...
		*		 ...
		*		 ...
		*		 ...
		* buckets.size()
		*/		 
		vector<node*> buckets;
	public:
		void initialize_buckets(size_type n)
		{
			auto next_size = [n]() {
				//���ش���n���������
				for (auto prime : prime_list)
				{
					if (prime > n)
						return prime;
				}
			};
			buckets.resize(next_size());
		}

		hashtable(size_type n)
		{
			buckets.resize(0);
		}
		
		//
		//��ʾ���֧�ֵ�buckets�Ƕ���
		//Ŀǰ��25165843
		//
		unsigned long max_buckets()
		{
			return prime_list[prime_list_size - 1];
		}

	};

}