/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:58:51 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/02/25 16:40:49 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap void constructor called" << std::endl;
	this->Hit_points= 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "ScavTrap default constructor called"  << std::endl;
	this->Hit_points= 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &others)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = others;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" <<  std::endl;
	return ;
}

void	ScavTrap::attack(const std::string& target)
{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing "
		<< Attack_damage << " points of damange!";
    Energy_points--;
    std::cout << "Your mana is " << Energy_points << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->get_name()
	<< " is on keeper-protector!" << std::endl;
	return ;
}
