/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:10:33 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/10 22:40:07 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

std::string HumanB::getName(void)
{
    return(this->name);
}

void    HumanB::setName(std::string name)
{
    this->name = name;
}
Weapon* HumanB::getWeapon(void)
{
    return(this->weapon);
}

void    HumanB::setWeapon(  Weapon &name)
{
    this->weapon = &name;
}

void    HumanB::attack(void)
{
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->weapon->getType() << std::endl;
}

HumanB::HumanB(std::string nam):weapon(NULL), name(nam){}