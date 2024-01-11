/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:47:31 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/11 14:25:20 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "ClapTrap-Default constructor called" << std::endl;

    name = "Ruggi";
    Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(std::string const _name){
    std::cout << "ClapTrap-String constructor called" << std::endl;

    name = _name;
    Hit_points = 10;
	Energy_points = 10;
	Attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const& other) {
	std::cout << "ClapTrap-Copy constructor called" << std::endl;

	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	return ;
}

std::string	ClapTrap::get_name(void) const
{
	return (this->name);
}

int	ClapTrap::get_Hp(void) const
{
	return (this->Hit_points);
}

int	ClapTrap::get_Ep(void) const
{
	return (this->Energy_points);
}

int	ClapTrap::get_Ad(void) const
{
	return (this->Attack_damage);
}

void	ClapTrap::operator = (ClapTrap const &Trap)
{
	std::cout << "Assignation operator called" << std::endl;
	name = Trap.get_name();
	Hit_points = Trap.get_Hp();
    Energy_points = Trap.get_Ep();
	Attack_damage = Trap.get_Ad();
	return ;
}

void ClapTrap::attack(std::string const& target) {
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
		<< Attack_damage << " points of damange!";
    Energy_points--;
    std::cout << "Your mana is " << Energy_points << std::endl;
}

void ClapTrap::takeDamange(unsigned int amount) {
	if ( Hit_points > (int)amount) 
    {
		Hit_points -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount
		   << " of damage. He now has " << Hit_points << " hp!" << std::endl;
	} 
    else 
    {
		Hit_points = 0;
		std::cout << "ClapTrap " << name << " takes " << amount
		   << " of damage. Killed" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	Hit_points += amount;
    Energy_points--;
    std::cout << "ClapTrap " << this->get_name()
	<< " is being repaired about " << amount << " points! He now has " << Hit_points << " hp left! Your mana is " << Energy_points << std::endl;
}