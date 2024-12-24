/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:50:33 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/12/24 15:50:34 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

const char* Form::GradeTooHighException::what() const throw()
{
	return "Error grade is too high\n";
}


const char* Form::GradeTooLowException::what() const throw()
{
	return "Error grade is too Low\n";
}

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) :
name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	sign = false;
	(void)sign;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToSign > 150)
		throw GradeTooLowException();
	std::cout<<"The form was printed"<<std::endl;
}

Form::~Form()
{
	std::cout<<"The form was scraped"<<std::endl;
}

int Form::getGradetoExecute(void) const
{
	return this->gradeToExecute;
}

int Form::getGradeToSign(void) const
{
	return this->gradeToSign;
}

const std::string Form::getName(void) const
{
	return this->name;
}

bool Form::getSign(void) const
{
	return this->sign;
}

Form::Form(Form& obj) : name(obj.getName()), sign(obj.getSign()), gradeToSign(obj.getGradeToSign()),
gradeToExecute(obj.getGradetoExecute())
{
	std::cout<<"The copy construttor of the form has been called"<<std::endl;
}

Form& Form::operator=(const Form& obj)
{
	this->sign = obj.getSign();
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os<<obj.getName()<<" Is Form name\n"<<obj.getGradeToSign()<<" grade required to sign it\n"
	<<obj.getGradetoExecute()<<" grade required to execute it\n"<<obj.getSign()<<" (0 not signed 1 signed)"<<std::endl;
	return os;
}

void Form::beSigned(Bureaucrat& theBur)
{
	if (theBur.getGrade() <= this->gradeToSign)
	{
		std::cout<<"the form got signed"<<std::endl;
		this->sign = true;
	}
	else
		throw GradeTooLowException();
}

