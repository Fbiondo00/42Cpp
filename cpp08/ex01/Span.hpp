
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	array;
		Span();
	public:
		Span(unsigned int n);
		~Span();
		Span(const Span& obj);
		Span&	operator=(const Span& obj);

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();

		void	allInOne();

		void	printCont();
};
