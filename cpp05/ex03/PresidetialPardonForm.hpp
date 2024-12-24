
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP


#include <string.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class AForm;

class PresidentialPardonForm : virtual public AForm
{
	private:
		const std::string target;

	public:
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm();
		std::string getTarget(void) const;
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);

		//methods inherited
		void execute(const Bureaucrat& executor) const;
};

#endif
