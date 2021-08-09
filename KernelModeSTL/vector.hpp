#pragma once
#include"include/global.hpp"

/***

*Revision History:
	2021/8/4	add pop_back()��front()��back()
	2021/8/5	add	erase()��resize()��clear()��		
****/

namespace std {



	template <typename T>
	class vector
	{
	public:
		using value_type = T;
		using size_type = size_t;
		using pointer = value_type*;
		using iterator = value_type*;
		using const_iterator = const iterator;
		using reference = value_type&;

		vector() : start(0), finish(0), end_of_storage(0) {}
		~vector();

		iterator begin()const { return start; }
		iterator end()const { return finish; }

		size_type size() const { return (size_type)(end() - begin()); }

		bool empty() const { return begin() == end(); }

		void push_back(const T& x);
		void pop_back() { --finish; destroy(finish); }
		void insert_aux(iterator position, const T& x);
		reference front(){ return *begin(); };
		reference back() { return *(end() - 1); };
		iterator erase(iterator position)
		{
			//���д�����ʵ��������list���棬��Ϊlist����ֱ��ɾ���ģ�ԭʼ��������ȻʧЧ������vector���ᣬ��Ϊ�����Ե�
			//iterator next = position++;
			
			/***
			*�����ݵ�STLԴ������p117��erase�����������п����
			*��ֻ�ж���Ҫɾ����λ�úͿ��ÿռ�����λ�ã�������ǵ�ǰʹ�ÿռ�����λ�ã�
			***/
			if (position >= finish)	//never return
				ExRaiseAccessViolation();
			
			if (position + 1 == finish)
			{
				--finish;
				destroy(finish);
				return position;
			}
			else
			{
				auto tmp = position;
				while (position < finish - 1)
				{
					destroy(position);
					auto next = position + 1;
					/*
						���ﲻ��Ҫ����next����Ϊ���Ǹտ�ʼ�õ���new[]���������ǵ������ܹ����ٸ�����
						������ʱ����delete[]������������ȷ�����Ǹտ�ʼ��������ж��󶼻ᱻ�������������
						Ҫ�����Ļ���vector�����������͵��Լ���start��finish�ͷŶ��󣬶�����delete[]
					*/
					construct(position, *next);
					destory(next);
					position++;

				}
				--finish;
				return tmp;
			}
		}
		iterator erase(iterator first, iterator last)
		{
			if (last > finish)
				ExRaiseAccessViolation();
			auto tmp = first;
			while ((first++) != last)
			{
				destroy(first - 1);
			}
			first = tmp;
			if (last < finish)
			{
				while ((last++) != finish)
				{
					construct(first, *(last - 1));
					destroy(last - 1);
					first++;
				}
			}
			finish = first;
		}
		void capacity()const { return size_type(end() - begin()); }
		reference operator[](size_type n) { return *(begin() + n); }
		
		/*
		*
		void insert(iterator postion, size_type n, const T& x)
		{
		
		}
		*/
		void resize(size_type new_size)
		{
			if (new_size < size()) {
				destroy<vector<T>>(begin() + new_size, finish);
				finish = begin() + new_size;
			}
			else if(new_size > size())
			{
				//�ռ�����Ҫ����ռ�����·���
				
				//����ԭ�����ڴ��ַ
				auto tmp = new T[new_size];
				auto new_start = tmp;
				auto old_start = start;
				while (start != finish) {
					construct(tmp, *start);
					destroy(start);
					start++;
					tmp++;
				}
				deallocate((size_t*)old_start - 1);
				start = new_start;
				finish = tmp;
				end_of_storage = start + new_size;

			}
		}
	private:
		//[this]
		iterator start;		//��ʾĿǰʹ�ÿռ��ͷ
		//[this+8]
		iterator finish;	//��ʾĿǰʹ�ÿռ��β
		//[this+16]
		iterator end_of_storage;//��ʾĿǰ���ÿռ��β

	};


	template<typename T>
	void vector<T>::push_back(const T& x)
	{
		if (finish < end_of_storage) {
			construct(finish, x);
			++finish;
		}
		else
		{
			insert_aux(end(), x);
		}
	}

	template<typename T>
	void vector<T>::insert_aux(vector<T>::iterator position, const T& x)
	{
		if (finish < end_of_storage)
		{
			construct(finish, x);
			++finish;
		}
		else {
			
			const size_type old_size = size();
			const size_type new_size = (!old_size) ? 1 : old_size * 2;

			iterator new_start = new T[new_size];//������ʵ��Ϊsizeof(T) * new_size,ʵ�ʷ�����size_t���ֽ�
			iterator new_finish = new_start;

			if (start != 0) {//ԭ��vector�д������ݣ��������ݿ�������vector��
				auto tmp = start;
				while (start < finish) {
					construct(new_finish, *start);
					new_finish++;
					start->~T();
					start++;
				}
				//�����ƶ���֮��ǵ��ͷ�
				deallocate((size_t*)tmp - 1);
			}
			
			end_of_storage = new_start + new_size;
			construct(new_finish, x);
			new_finish++;
			start = new_start;
			finish = new_finish;
		}

	}

	template<typename T>
	vector<T>::~vector()
	{
		/*
			�����������������start->~T();
		*/
		//delete[] start;
		destroy<vector<T>>(start, finish);
		deallocate((size_t*)start-1);
	}

}

static_assert(sizeof(std::vector<int>) == 0x18);