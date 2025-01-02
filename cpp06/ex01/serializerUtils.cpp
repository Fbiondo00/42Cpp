

#include "utils.h"

void	dataInit(Data& var)
{
	std::cout<<"Data variable init"<<std::endl;
	var.age = 24;
	var.name = "Flavio";
	var.lastName = "Biondo";
	var.married = false;
}

void	dataPrint(Data& var)
{
	std::cout<<"Name: "<<var.name<<std::endl;
	std::cout<<"Last name: "<<var.lastName<<std::endl;
	std::cout<<"Age: "<<var.age<<std::endl;
	std::cout<<"Married: "<<var.married<<std::endl;
}
