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
		//因为只有下一个节点的指针
		//以此封装的迭代器只支持前进操作，不支持后退，也没有逆向迭代器
		_hashtable_node* next;
		value val;
	};

	template<class value,
		class key,
		class HashFcn >//应该提供默认的hash函数
		class hashtable
	{

		using node = _hashtable_node<value>;
		using size_type = size_t;

	private:
		//如果buckets太少，会导致挂接链表太长，java中jdk会把这种情况转化为红黑树
		vector<node*> buckets;
	public:
		void initialize_buckets(size_type n)
		{
			auto next_size = [n]() {
				//返回大于n的最大质数
			};
		}

		hashtable(size_type n)
		{
			buckets.resize(0);
		}
		
	};

}