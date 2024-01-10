/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:13:01 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/10 16:41:01 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{
	Fixed	a(4);
	Fixed	b(5.05f);
	Fixed	c(b);
	bool	cond;

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;

	std::cout << std::endl;

	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << b << " / " << a << " = " << b / a << std::endl;

	std::cout << std::endl;

	cond = c < b;
	std::cout << c << " < " << b << " = " << cond << std::endl;
	cond = c > b;
	std::cout << c << " > " << b << " = " << cond << std::endl;
	cond = a < b;
	std::cout << a << " < " << b << " = " << cond << std::endl;
	cond = c > a;
	std::cout << c << " > " << a << " = " << cond << std::endl;
	cond = c <= b;
	std::cout << c << " <= " << b << " = " << cond << std::endl;
	cond = c >= b;
	std::cout << c << " >= " << b << " = " << cond << std::endl;
	cond = c == b;
	std::cout << c << " == " << b << " = " << cond << std::endl;
	cond = c == a;
	std::cout << c << " == " << a << " = " << cond << std::endl;

	std::cout << std::endl;

	std::cout << a++ << " a++ " << a << std::endl;
	std::cout << b++ << " b++ " << b << std::endl;
	std::cout << a-- << " a-- " << a << std::endl;
	std::cout << b-- << " b-- " << b << std::endl;

	std::cout << std::endl;

	std::cout << a++ << " ++a " << a << std::endl;
	std::cout << ++b << " ++b " << b << std::endl;
	std::cout << --a << " --a " << a << std::endl;
	std::cout << --b << " --b " << b << std::endl;

	return 0;
}