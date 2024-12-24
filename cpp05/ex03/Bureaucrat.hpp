
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP



#include <string.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class AForm;

class Bureaucrat
{

	private:
		const std::string	name;
		int					grade;

	public:
		// Bureaucrat(const std::string name, int grade);
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
		void				signForm(AForm& obj);
		//ex02
		void				executeForm(AForm const & form);

		//exception implementation
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
