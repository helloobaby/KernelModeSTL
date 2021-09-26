#pragma once
#include"include/global.hpp"


template<typename _A1,typename _A2,typename _R>
struct binary_function
{
	using first_argument_type = _A1;
	using second_argument_type = _A2;
	using result_type = _R;
};

template <typename _Ty>
struct less : public binary_function<_Ty,_Ty,bool>
{
	bool operator(const _Ty& _left, const _Ty& _right) const
	{
		//默认小于运算
		return(_left < _right);
	}
};

template <typename _Ty>
struct greater : public binary_function<_Ty, _Ty, bool>
{
	bool operator(const _Ty& _left, const _Ty& _right) const
	{
		//默认小于运算
		return(_left > _right);
	}
};