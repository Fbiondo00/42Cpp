/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:18:14 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/26 21:31:06 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
// In pratica, questo array p ti consente di accedere e chiamare dinamicamente
// le quattro funzioni membro della classe Harl attraverso gli indici dell'array
#include "Harl.hpp"

// I W D E % 10
// 3 7 8 9 % 7
// 3 0 1 2

void	Harl::complain(std::string level)
{
	void	(Harl::*p[4])() = {&Harl::warning, &Harl::debug, &Harl::error, &Harl::info};

	switch (level[0] % 10 % 7)
	{
		case 1:
			(this->*p[1])();
		case 3:
			(this->*p[3])();
		case 0:
			(this->*p[0])();
		case 2:
			(this->*p[2])();
    }
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!\n" << std::endl;
	return ;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
	return ;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month.\n" << std::endl;
	return ;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
	return ;
}
