

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include "utils.h"
#include <stdint.h>



class Serializer
{
	private:
		Serializer();
	public:
		~Serializer();
		Serializer(const Serializer& obj);
		Serializer& operator=(const Serializer& obj);
		//It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(struct Data* ptr);
		//It takes an unsigned integer parameter and converts it to a pointer to Data.
		static struct Data* deserialize(uintptr_t raw);
};




#endif
