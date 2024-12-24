
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyForm", 72, 45), target(target)
{
	std::cout<<"The shruberry has been created"<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout<<"The shruberry got destroyed"<<std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
	return this->target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.getTarget())
{
	std::cout<<"The copy constructor of shruberry has been called"<<std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	// this->target = obj.target;
	(void)obj;
	return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout<<"You want to get modified huh? let's what can you do"<<std::endl;
	if (this->getSign() == true)
	{
		if (executor.getGrade() <= this->getGradetoExecute())
		{
			if (rand() % 2)
				std::cout<<"The robotomy was failure you're now a cow 🐄"<<std::endl;
			else
				std::cout<<"The robotomy was a success you're ready to go"<<std::endl;
		}
		else
			throw GradeTooLowException();
	}
	else
		throw NotSignedException();
}
