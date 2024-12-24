
#include "AForm.hpp"

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Error grade is too high\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Error grade is too Low\n";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Error the form is not signed\n";
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) :
name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	sign = false;
	(void)sign;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout<<"The Aform was printed"<<std::endl;
}

AForm::~AForm()
{
	std::cout<<"The Aform was scraped"<<std::endl;
}

int AForm::getGradetoExecute(void) const
{
	return this->gradeToExecute;
}

int AForm::getGradeToSign(void) const
{
	return this->gradeToSign;
}

std::string AForm::getName(void) const
{
	return this->name;
}

bool AForm::getSign(void) const
{
	return this->sign;
}

AForm::AForm(const AForm& obj) : name(obj.getName()), gradeToSign(obj.getGradeToSign()),
gradeToExecute(obj.getGradetoExecute())
{
	std::cout<<"The copy construttor of the Aform has been called"<<std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this != &obj)
		this->sign = obj.getSign();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os<<obj.getName()<<" Is AForm name\n"<<obj.getGradeToSign()<<" is the grade required to sign it\n"
	<<obj.getGradetoExecute()<<" is the grade required to execute it\n"<<obj.getSign()<<" (0 not signed 1 signed)"<<std::endl;
	return os;
}

void AForm::beSigned(Bureaucrat& theBur)
{
	if (theBur.getGrade() <= this->gradeToSign)
	{
		std::cout<<"the Aform got signed"<<std::endl;
		this->sign = true;
	}
	else
		throw GradeTooLowException();
}

