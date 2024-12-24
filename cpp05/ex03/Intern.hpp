
#ifndef INTERN_HPP
#define INTERN_HPP


#include <string.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "ShruberryCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidetialPardonForm.hpp"

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern& operator=(const Intern& obj);

		AForm*	makeForm(std::string formType, std::string formName);

};

#endif
