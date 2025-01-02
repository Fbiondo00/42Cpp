

#include "utils.h"

void	printConv(int doNotPrintChar, int printChar, char cArgv)
{
	if ((printChar == 2) || (!doNotPrintChar && (ScalarConverter::conInt <= 127 && ScalarConverter::conInt >= 32)))
	{
		if (printChar == 2 && std::isprint(ScalarConverter::conInt))
			std::cout<<"char: '"<<cArgv<<"'"<<std::endl;
		else if (std::isprint(ScalarConverter::conInt))
			std::cout<<"char: '"<<ScalarConverter::conChar<<"'"<<std::endl;
		else
			std::cout<<"char: Non displayable"<<std::endl;
	}
	else
		std::cout<<"char: Impossible"<<std::endl;
	if (doNotPrintChar == 1)
	{
		std::cout<<"int: not possible"<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1)<<"float: "<<ScalarConverter::conFloat<<"f"<<std::endl;
		std::cout<<"double: "<<ScalarConverter::conDouble<<std::endl;
	}
	else if (doNotPrintChar == 2)
	{
		std::cout<<"int: not possible"<<std::endl;
		std::cout<<"float: not possible"<<std::endl;
		std::cout<<"double: "<<ScalarConverter::conDouble<<std::endl;
	}
	else if (doNotPrintChar == 3)
	{
		std::cout<<"int: not possible"<<std::endl;
		std::cout<<"float: not possible"<<std::endl;
		std::cout<<"double: not possible"<<std::endl;
	}
	else
	{
		std::cout<<"int: "<<ScalarConverter::conInt<<std::endl;
		std::cout<<std::fixed<<std::setprecision(1)<<"float: "<<ScalarConverter::conFloat<<"f"<<std::endl;
		std::cout<<"double: "<<ScalarConverter::conDouble<<std::endl;
	}
}

int	halfLiteralsCheck(std::string argv)
{
	if (!argv.compare("nan") || !argv.compare("-nan")
	|| !argv.compare("+nan") || !argv.compare("inf")
	|| !argv.compare("-inf") || !argv.compare("+inf"))
		return (1);
	else if (argv.size() == 1)
	{
		return (2);
	}
	return (0);
}

void	printHalfLiteral(std::string value)
{
	std::cout<<"char: impossible"<<std::endl;
	std::cout<<"int: impossible"<<std::endl;
	std::cout<<"float: "<<value<<"f"<<std::endl;
	std::cout<<"double: "<<value<<std::endl;
}

// Restores the stream clear

int	checkUnderOverflow(std::string value)
{
	std::stringstream converter(value);
	converter >> ScalarConverter::conDouble;
	if (!converter)
		return (3);
	converter.clear();
	converter.seekg(0);
	converter >> ScalarConverter::conFloat;
	if (!converter)
		return (2);
	converter.clear();
	converter.seekg(0);
	converter >> ScalarConverter::conInt;
	if (!converter)
		return (1);
	return (0);
}

