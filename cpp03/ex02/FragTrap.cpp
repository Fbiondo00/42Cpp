/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 16:12:41 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/02/26 16:23:46 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
    std::cout << "FragTrap-Default constructor called" << std::endl;

    name = "RuggiTrap";
    Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
}

FragTrap::FragTrap(std::string const _name): ClapTrap(){
    std::cout << "FragTrap-String constructor called" << std::endl;

    name = _name;
    Hit_points = 100;
	Energy_points = 100;
	Attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const &other) {
	std::cout << "FragTrap-Copy constructor called" << std::endl;

	*this = other;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
	return ;
}


void FragTrap::attack(std::string const& target) {
	std::cout << "FragTrap " << name << " attacks " << target << ", causing "
		<< Attack_damage << " points of damange!";
    Energy_points--;
    std::cout << "Your mana is " << Energy_points << std::endl;
}

void FragTrap::takeDamange(unsigned int amount) {
	if ( Hit_points > (int)amount) 
    {
		Hit_points -= amount;
		std::cout << "FragTrap " << name << " takes " << amount
		   << " of damage. He now has " << Hit_points << " hp!" << std::endl;
	} 
    else 
    {
		Hit_points = 0;
		std::cout << "FragTrap " << name << " takes " << amount
		   << " of damage. Killed" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	Hit_points += amount;
    Energy_points--;
    std::cout << "FragTrap " << this->get_name()
	<< " is being repaired about " << amount << " points! He now has " << Hit_points << " hp left! Your mana is " << Energy_points << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << name << "is highFivesGuys!"
		<< std::endl;
}