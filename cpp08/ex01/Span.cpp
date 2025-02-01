

#include "Span.hpp"
#include <climits>

Span::Span(unsigned int n) : N(n)
{

	std::cout<<"Constructor called"<<std::endl;
}

Span::~Span()
{
	std::cout<<"span destructor called"<<std::endl;
}

Span::Span(const Span& obj) : N(obj.N), array(obj.array)
{
	std::cout<<"Copy constructor called"<<std::endl;
}

Span&	Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		this->array = obj.array;
	}
	return *this;
}


void	Span::addNumber(int	number)
{
	if (this->array.size() == this->N)
		throw std::runtime_error("MAX");
	this->array.push_back(number);
}

int	Span::shortestSpan()
{
	int	shortest  = 2147483647;

	if (this->array.size() < 2)
		throw std::runtime_error("ci sono 2 elementi");
	for (std::vector<int>::iterator it = array.begin(); it != array.end(); ++it)
	{
		for (std::vector<int>::iterator jt = array.begin(); jt != array.end(); ++jt)
		{
			if (it != jt)
			{
				int currentDist = std::abs(*it - *jt);
				if (currentDist < shortest)
					shortest = currentDist;
			}
		}
	}
	return (shortest);
}

int	Span::longestSpan()
{
	if (this->array.size() < 2)
		throw std::runtime_error("ci sono 2 elementi");

	std::vector<int>::iterator max = std::max_element(this->array.begin(), this->array.end());
	std::vector<int>::iterator min = std::min_element(this->array.begin(), this->array.end());
	return (*max - *min);
}

void	Span::printCont()
{
	std::vector<int>::iterator	it;

	for (it = this->array.begin(); it != this->array.end(); ++it)
	{
		std::cout<<*it<<std::endl;
	}
}

void	Span::allInOne()
{
	srand((time(0)));
	std::vector<int>	copyClone(this->N);
	std::vector<int>::iterator	begin = copyClone.begin();
	std::vector<int>::iterator	end = copyClone.end();
	for (std::vector<int>::iterator ptr = begin; ptr != end; ++ptr)
	{
		addNumber(rand() % 1000);
	}
}

