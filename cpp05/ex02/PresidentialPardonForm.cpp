

#include "PresidetialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialForm", 25, 5), target(target)
{
	std::cout<<"The presidential form has been created"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout<<"The presidential form has been scrapped"<<std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return this->target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.getTarget())
{
	std::cout<<"The presidential form copy constructor has been called"<<std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	std::cout<<"The presidential form overloading operator has been called"<<std::endl;
	// this->target = obj.getTarget();
	(void)obj;
	return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	std::cout<<"You want to have the permission for the president huh?"<<std::endl;
	std::cout<<"Let me check if the form is signed before the permission"<<std::endl;
	if (this->getSign() == true)
	{
		std::cout<<"ok let's see if you can have the permission of the president"<<std::endl;
		if (executor.getGrade() <= 5)
			std::cout<<"mr "<<this->getTarget()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}

