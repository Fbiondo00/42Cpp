#pragma once


#include <iostream>

template <typename T>

void	swap(T& t1, T& t2)
{
	T	tmp = t1;

	t1 = t2;
	t2 = tmp;
}

template <typename T>

T	max(T t1, T t2)
{
	if (t1 > t2)
		return (t1);
	return (t2);
}


template <typename T>

T	min(T t1, T t2)
{
	if (t1 < t2)
		return (t1);
	return (t2);
}
