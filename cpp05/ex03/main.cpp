

#include "Intern.hpp"
#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidetialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	first("Andromeda",3);
		Bureaucrat	second("Sirio", 10);
		Bureaucrat	third("Phoenix", 15);
		Intern	doItForMe;

		AForm	*randomStuff(doItForMe.makeForm("shruberry request", "alberello"));
		first.signForm(*randomStuff);
		second.executeForm(*randomStuff);
		delete randomStuff;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
