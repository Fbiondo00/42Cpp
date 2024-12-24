
#include "Intern.hpp"


Intern::Intern()
{
	std::cout<<"This constructor is as useful as concrete parachute. " <<std::endl;
}

Intern::~Intern()
{
	std::cout<<"Intern Destructor called"<<std::endl;
}

Intern::Intern(const Intern& obj)
{
	std::cout<<"This copy constructor is as useful as Pedals on a wheelchair "<<std::endl;
	(void)obj;
}

Intern& Intern::operator=(const Intern& obj)
{
	std::cout<<"This operator overloading is as useful as a case sensitive search engine"<<std::endl;
	(void)obj;
	return *this;
}

AForm*	Intern::makeForm(std::string formType, std::string formName)
{
	AForm	*test = 0;

	if (formType.compare("shruberry request") != 0 && formType.compare("robotomy request") && formType.compare("presidential request") )
	{
		throw std::runtime_error("This kind of form doesn't exist\n");
	}
	switch (formType[0])
	{
		case 's':
		{
			test = new ShruberryCreationForm(formName);
			break ;
		}
		case 'r':
		{
			test = new RobotomyRequestForm(formName);
			break ;
		}
		case 'p':
		{
			test = new PresidentialPardonForm(formName);
		}
	}
	return test;
}
