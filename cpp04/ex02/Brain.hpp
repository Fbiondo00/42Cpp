#pragma once

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &b);
		~Brain(void);

		void	operator = (Brain const &brain);

		std::string const	*getIdeas(void) const;
	private:
		std::string	id[100];
};