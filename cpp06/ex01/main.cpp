
#include "utils.h"



int	main(void)
{
	Data	base;
	Data	*pBase;
	Data	*cecker;

	uintptr_t	serial;

	dataInit(base);


	pBase = &base;
	dataPrint(*pBase);
	serial = Serializer::serialize(pBase);

	cecker = Serializer::deserialize(serial);
	dataPrint(*pBase);
	dataPrint(*cecker);

	std::cout<<"Check of the address:\n"<<pBase<<" the copy "<<cecker<<std::endl;
	if (pBase == cecker)
		std::cout<<"all ok"<<std::endl;
	return (0);
}
