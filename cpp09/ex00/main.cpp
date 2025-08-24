#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac == 2)
	{
		BitcoinExchange exchange;
		exchange.start(av[1]);
	}
	else
	{
		std::cerr << "Usage: ./btc [input.(txt/csv)]" << std::endl;
		return 1;
	}
	return 0;
}