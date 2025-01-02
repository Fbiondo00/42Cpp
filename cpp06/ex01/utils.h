

#ifndef UTILS_H
#define UTILS_H

#include "Serializer.hpp"


struct Data
{
	std::string	name;
	std::string	lastName;
	int			age;
	bool		married;
};

void	dataInit(struct Data& var);
void	dataPrint(struct Data& var);
#endif
