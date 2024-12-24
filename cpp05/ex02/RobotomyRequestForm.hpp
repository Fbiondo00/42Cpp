

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm :  virtual public AForm
{
	private:
		const std::string target;

	public:
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm();
		std::string getTarget(void) const;
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);

		//AForm method inherited
		void		execute( const Bureaucrat& executor) const;
};

#endif
