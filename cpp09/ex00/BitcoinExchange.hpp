#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iomanip>

class BitcoinExchange
{
	private:
		std::multimap<std::string, double> _datacsv;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange &operator=(BitcoinExchange const &obj);
		BitcoinExchange(BitcoinExchange const &obj);
		void start(std::string const &filename);
        void checkFileValidity(const std::string &filename);
		void loadDBExchangeRates();
		void parseInput(std::string const &filename);
		void calculateAndPrintBitcoinValues(std::string const &date, double const rate);
};
