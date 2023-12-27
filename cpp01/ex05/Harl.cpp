/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:05:12 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/26 21:49:51 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
// I W D E % 10
// 3 7 8 9 % 7
// 3 0 1 2
// In pratica, questo array p ti consente di accedere e chiamare dinamicamente
// le quattro funzioni membro della classe Harl attraverso gli indici dell'array
void	Harl::complain(std::string level)
{
	void	(Harl::*p[4])() = {&Harl::warning, &Harl::debug, &Harl::error, &Harl::info};
	(this->*p[level[0] % 10 % 7])();
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
	<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
	<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
