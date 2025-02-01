
#include "Span.hpp"


int	main(void)
{
	Span test1 = Span(5);

	test1.addNumber(6);
	test1.addNumber(3);
	test1.addNumber(17);
	test1.addNumber(9);
	test1.addNumber(11);

	std::cout << test1.shortestSpan() << std::endl;
	std::cout << test1.longestSpan() << std::endl;

	Span test(10);

	test.allInOne();
	std::cout<< test.shortestSpan()<<std::endl;

	test.printCont();
	return (0);
}
