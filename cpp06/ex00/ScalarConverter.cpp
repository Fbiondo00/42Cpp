
#include "utils.h"

char	ScalarConverter::conChar;
int		ScalarConverter::conInt;
float	ScalarConverter::conFloat;
double	ScalarConverter::conDouble;


ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return *this;
}

void	ScalarConverter::convert(std::string value)
{
	int	overflow = 0;
	int	printChar = 0;
	if (value[0] == ' ' && value.size() == 1)
	{
		std::cout<<"char: ' '"<<std::endl;
		std::cout<<"int: 32"<<std::endl;
		std::cout<<"float: 32.0f"<<std::endl;
		std::cout<<"double: 32.0"<<std::endl;
	}
	else
	{
		if ((printChar = halfLiteralsCheck(value)) && (halfLiteralsCheck(value) == 1))
			printHalfLiteral(value);
		else if (printChar != 0)
		{
			std::cout<<"printchar value "<<printChar<<std::endl;
			std::stringstream converter(value);
			converter >> ScalarConverter::conChar;
			if (ScalarConverter::conChar >= '0' && ScalarConverter::conChar <= '9')
			{
				ScalarConverter::conDouble = static_cast<double>(ScalarConverter::conChar - 48);
				ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
				ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
			}
			else
			{
				ScalarConverter::conDouble = static_cast<double>(ScalarConverter::conChar);
				ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
				ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
			}
			printConv(overflow, printChar, value[0]);
		}
		else if (printChar != 1)//hypothetic check for normal chars
		{
			overflow = checkUnderOverflow(value);
			std::stringstream converter(value);
			converter >> ScalarConverter::conDouble;
			ScalarConverter::conFloat = static_cast<float>(ScalarConverter::conDouble);
			ScalarConverter::conInt = static_cast<int>(ScalarConverter::conDouble);
			ScalarConverter::conChar = static_cast<char>(ScalarConverter::conInt);
			printConv(overflow, printChar, value[0]);
		}
	}
}
