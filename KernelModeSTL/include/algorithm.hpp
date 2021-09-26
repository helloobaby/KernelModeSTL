#pragma once
#include"include/global.hpp"

namespace std
{

	template <typename T>
	void sort(typename T::iterator, typename T::iterator)
	{
		//
		//快排+堆排+选择
		//

	}

	template <class InputIterator,typename T>
	InputIterator find(InputIterator first, InputIterator last, const T& value)
	{
		//
		//一定得是*first != value，而不是value != *first
		//
		while (first != last && *first != value)
			first++;

		return first;
	}






































}