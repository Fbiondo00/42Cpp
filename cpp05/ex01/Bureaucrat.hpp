

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string.h>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"
class Form;

class Bureaucrat
{

	private:
		const std::string	name;
		int					grade;
		Bureaucrat();

	public:
		// Bureaucrat(const std::string name, int grade);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		const Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(Form& obj);
		//exceptions override
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
