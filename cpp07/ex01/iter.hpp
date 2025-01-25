
#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T, typename Func>
void	iter(T *array, int size, Func func)
{
	for (int i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void	call(T arrayValue)
{
	std::cout<<"value of the array "<<arrayValue<<std::endl;
}


#endif
