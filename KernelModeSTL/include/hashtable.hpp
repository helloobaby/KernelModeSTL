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
		* table size一般是要为质数的
		* 防止极端情况比如 60 % table size 、80 % table size 、 100 % table size
		* 都会得到index为0这种情况
		*/
		53,97,193,389,769,
		1543,3079,6151,12289,24593,
		49157,98317,196613,393241,786433,
		1572869,3145739,6291469,12582917,25165843
	};

	template <typename value>
	struct _hashtable_node
	{
		//因为只有下一个节点的指针
		//以此封装的迭代器只支持前进操作，不支持后退，也没有逆向迭代器
		_hashtable_node* next;
		value val;
	};

	template<class value,
			class key,
			class HashFcn>//应该提供默认的hash函数
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
				//返回大于n的最大质数
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
		//表示最大支持的buckets是多少
		//目前是25165843
		//
		unsigned long max_buckets()
		{
			return prime_list[prime_list_size - 1];
		}

	};

}