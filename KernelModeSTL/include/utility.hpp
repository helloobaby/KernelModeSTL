#pragma once
#include"./include/global.hpp"

template<class _Ty1,
	class _Ty2> struct pair
{	// store a pair of values
	typedef pair<_Ty1, _Ty2> _Myt;
	typedef _Ty1 first_type;
	typedef _Ty2 second_type;

	pair()
		: first(_Ty1()), second(_Ty2())
	{	// construct from defaults
	}
	pair(const _Ty1& _Val1, const _Ty2& _Val2)
		: first(_Val1), second(_Val2)
	{	// construct from specified values
	}
	template<class _Other1,
		class _Other2>
		pair(const pair<_Other1, _Other2>& _Right)
		: first(_Right.first), second(_Right.second)
	{	// construct from compatible pair
	}

	_Ty1 first;	// the first stored value
	_Ty2 second;	// the second stored value
};