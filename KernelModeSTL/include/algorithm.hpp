#pragma once
#include"include/global.hpp"

namespace std
{

	template <typename T>
	void sort(typename T::iterator, typename T::iterator)
	{
		//
		//����+����+ѡ��
		//

	}

	template <class InputIterator,typename T>
	InputIterator find(InputIterator first, InputIterator last, const T& value)
	{
		//
		//һ������*first != value��������value != *first
		//
		while (first != last && *first != value)
			first++;

		return first;
	}






































}