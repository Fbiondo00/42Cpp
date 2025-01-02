

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <limits>
#include <string.h>
#include <cstdlib> //library for convertion
#include <cctype> //to help me do checks for chars
#include <sstream> //to do the convertion in a styled way
#include <iomanip> //in this way i can print the numbers with the point more precisely
#include <stdint.h>


class Base
{
	public:
		virtual	~Base();
};

class A : public Base
{
	public:
		A();
		virtual ~A();
};


class B : public Base
{
	public:
		B();
		virtual ~B();
};

class C : public Base
{
	public:
		C();
		virtual ~C();
};

Base *	generate(void);
void	identify(Base* p);
void	identify(Base& p);
#endif

