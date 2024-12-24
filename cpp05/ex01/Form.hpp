/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:50:46 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/12/24 15:56:37 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FORM_HPP
#define FORM_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class Form
{

	private:
		const std::string	name;
		bool				sign;
		const int			gradeToSign;
		const int			gradeToExecute;

	public:
		Form(const std::string name = "default", const int gradeToSign = 25, const int gradeToExecute = 10);
		// Form(const std::string name, const int gradeToSign, const int gradeToExecute);
		~Form();
		Form(Form& obj);
		Form& operator=(const Form &obj);

		const std::string	getName(void) const;
		bool				getSign(void) const;
		int					getGradeToSign(void) const;
		int					getGradetoExecute(void) const;
		void				beSigned(Bureaucrat& theBur);
		//exception
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

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif

