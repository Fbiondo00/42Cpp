

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute);
		// AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
		virtual ~AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm &obj);

		std::string	getName(void) const;
		bool				getSign(void) const;
		int					getGradeToSign(void) const;
		int					getGradetoExecute(void) const;
		void				beSigned(Bureaucrat& theBur);
		virtual void		execute(const Bureaucrat& executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif

