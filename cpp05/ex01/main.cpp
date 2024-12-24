

#include <string.h>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	firstDay("Davide", 11);
		Form		firstForm("Possibility to drive", 10, 2);

		// firstForm.beSigned(firstDay);
		std::cout<<firstForm<<std::endl;
		firstDay.signForm(firstForm);
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
