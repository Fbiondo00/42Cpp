/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:38:36 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/12/24 15:41:26 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include <string.h>
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	public:
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

	private:
		const std::string	name;
		int					grade;

	public:
		Bureaucrat(const std::string name = "jim", int grade = 25);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& obj);
		const Bureaucrat& operator=(const Bureaucrat& obj);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				setGrade(int grade);
		void				incrementGrade();
		void				decrementGrade();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
