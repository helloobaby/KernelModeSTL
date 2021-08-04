#pragma once
#include"include/global.hpp"

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
		iterator end()const  { return finish; }

		size_type size() const { return (size_type)(end()-begin()); }

		bool empty() const { return begin() == end(); }

		void push_back(const T& x);

		void insert_aux(iterator position, const T& x);

	private:
		//[this]
		iterator start;		//表示目前使用空间的头
		//[this+8]
		iterator finish;	//表示目前使用空间的尾
		//[this+16]
		iterator end_of_storage;//表示目前可用空间的尾

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

			iterator new_start = new T[new_size];//编译器实现为sizeof(T) * new_size,实际分配会加size_t个字节
			iterator new_finish = new_start;

			if (start != 0) {
				iterator tmp_start = start;
				while (tmp_start < finish) {
					construct(new_finish, *tmp_start);
					new_finish++;
					tmp_start++;
				}
				delete[] start;
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
		//编译器会替我们逐个start->~T();
		delete[] start;
	}

}

static_assert(sizeof(std::vector<int>) == 0x18);