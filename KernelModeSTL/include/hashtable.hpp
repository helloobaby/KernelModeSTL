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

	template <typename key,typename value>
	struct _hashtable_node
	{
		//因为只有下一个节点的指针
		//以此封装的迭代器只支持前进操作，不支持后退，也没有逆向迭代器
		_hashtable_node* next;
		key k;
		value val;
		
	};


	template<typename key, typename value, typename HashFcn>
	struct __hashtable_iterator
	{
		using reference = value&;
		using pointer = value*;
		using node = _hashtable_node<key, value>;

		node* cur;

		__hashtable_iterator(node* n) { cur = n; }
		
		reference operator*()const { return cur->val; }


	};

	template<class key,
			class value,
			class HashFcn = std::hash<key>>//应该提供默认的hash函数
	class hashtable
	{
		using node = _hashtable_node<key,value>;
		using size_type = size_t;
		using iterator = __hashtable_iterator<key, value,HashFcn>;

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
#ifndef DBG //Release编译的时候都是private的
		vector<node*> buckets;
		size_type num_elements;
#endif // !DBG
		public: // DEBUG编译ide时候都是public的，方便输出
#ifdef DBG
		vector<node*> buckets;
		//
		//这个干嘛用的？
		//
		size_type num_elements;
#endif // DEBUG

		//
		//决定buckets的大小
		//
		void initialize_buckets(size_type n)
		{
#pragma warning(disable: 4715)
			auto next_size = [n]() {
				//返回大于n的最大质数
				for (auto prime : prime_list)
				{
					if (prime > n)
						return prime;
				}
			};
			buckets.resize(next_size());
			//
			//对vector中的node初始化为nullptr
			//这里foreach用不了，因为此时vector内还没有东西，要从begin到end而不是finish
			// 
			//
#if 0
			for (auto& node : buckets)
			{
				node = nullptr;
			}
#endif		
			
			num_elements = 0;
		}

		//
		//默认构造函数
		//
		hashtable()
		{
			//
			//初始化53个node，太小导致哈希冲突严重
			//太大导致内存浪费严重，后期看情况改一改
			//
			initialize_buckets(0);
		}

		//
		//表示最大支持的buckets是多少
		//目前是25165843(0x1800013)
		//
		unsigned long max_buckets()
		{
			return prime_list[prime_list_size - 1];
		}

		//
		//bkt_num确定某个obj该放哪个位置,返回下标(索引)
		//
		size_t bkt_num(key obj)
		{
#if 0
			DbgBreakPoint();
			Log("%x\n", buckets.size());
#endif
			return HashFcn()(obj) % buckets.capacity();
		}

		//
		//向hashtable中插入数据
		//
		iterator insert(key k, value val)
		{
			//
			//算出这个数据落地点
			//
			const size_type n = bkt_num(k);
#if 1
			Log("bkt_num return %x\n", n);
#endif
			node* first = buckets[n];
			DbgBreakPoint();
			if (!first)
			{
				//
				//落地点为空，直接写value
				//
				first = new node;
#if 1
				Log("node at %p\n", first);
#endif
				first->val = val;
				first->k = k;
			}
			else
			{
				//
				//哈希冲突了。遍历链表，找到后面的空的再加一个节点，如果值重复了就直接返回
				//
			}

			return first;
		}

	};















}