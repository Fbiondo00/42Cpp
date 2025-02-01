#pragma once

#include <iostream>
#include <list>
#include <stack>
#include <iterator>
#include <vector>
#include <algorithm>
#include <deque>

template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(){}
		~MutantStack(){}
		MutantStack(const MutantStack& obj)
		{
			if (*this != obj)
				*this = std::stack<T, Container>::operator=(obj);
		}

		MutantStack& operator=(const MutantStack& obj)
		{
			if (*this != obj)
				this->c = obj.c;
			return *this;
		}

		typedef typename Container::iterator iterator;

		iterator	begin()
		{
			return (this->c.begin());
		}

		iterator end()
		{
			return (this->c.end());
		}

};



