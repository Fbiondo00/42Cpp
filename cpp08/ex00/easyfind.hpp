#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void	easyfind(const std::vector<T>& intContainer, int find)
{
	std::vector<int>::const_iterator	finder = std::find(intContainer.begin(), intContainer.end(), find);

	if (finder != intContainer.end())
		std::cout<<"Numero trovatoooo"<<std::endl;
	else
		throw std::runtime_error("Numero non trovato\n");
}

