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

	template <typename key,typename value>
	struct _hashtable_node
	{
		//��Ϊֻ����һ���ڵ��ָ��
		//�Դ˷�װ�ĵ�����ֻ֧��ǰ����������֧�ֺ��ˣ�Ҳû�����������
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
			class HashFcn = std::hash<key>>//Ӧ���ṩĬ�ϵ�hash����
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
#ifndef DBG //Release�����ʱ����private��
		vector<node*> buckets;
		size_type num_elements;
#endif // !DBG
		public: // DEBUG����ideʱ����public�ģ��������
#ifdef DBG
		vector<node*> buckets;
		//
		//��������õģ�
		//
		size_type num_elements;
#endif // DEBUG

		//
		//����buckets�Ĵ�С
		//
		void initialize_buckets(size_type n)
		{
#pragma warning(disable: 4715)
			auto next_size = [n]() {
				//���ش���n���������
				for (auto prime : prime_list)
				{
					if (prime > n)
						return prime;
				}
			};
			buckets.resize(next_size());
			//
			//��vector�е�node��ʼ��Ϊnullptr
			//����foreach�ò��ˣ���Ϊ��ʱvector�ڻ�û�ж�����Ҫ��begin��end������finish
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
		//Ĭ�Ϲ��캯��
		//
		hashtable()
		{
			//
			//��ʼ��53��node��̫С���¹�ϣ��ͻ����
			//̫�����ڴ��˷����أ����ڿ������һ��
			//
			initialize_buckets(0);
		}

		//
		//��ʾ���֧�ֵ�buckets�Ƕ���
		//Ŀǰ��25165843(0x1800013)
		//
		unsigned long max_buckets()
		{
			return prime_list[prime_list_size - 1];
		}

		//
		//bkt_numȷ��ĳ��obj�÷��ĸ�λ��,�����±�(����)
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
		//��hashtable�в�������
		//
		iterator insert(key k, value val)
		{
			//
			//������������ص�
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
				//��ص�Ϊ�գ�ֱ��дvalue
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
				//��ϣ��ͻ�ˡ����������ҵ�����Ŀյ��ټ�һ���ڵ㣬���ֵ�ظ��˾�ֱ�ӷ���
				//
			}

			return first;
		}

	};















}