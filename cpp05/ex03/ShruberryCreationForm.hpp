
#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"


class ShruberryCreationForm : virtual public AForm
{
	private:
		const std::string target;

	public:
		ShruberryCreationForm(const std::string& target);
		~ShruberryCreationForm();
		std::string getTarget(void) const;
		ShruberryCreationForm(const ShruberryCreationForm& obj);
		ShruberryCreationForm& operator=(const ShruberryCreationForm& obj);

		//AForm method inherited
		virtual void		execute(const Bureaucrat& executor) const;

};

#endif
