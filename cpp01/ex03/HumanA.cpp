/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:10:27 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/10 22:29:11 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

std::string HumanA::getname(void)
{
    return(this->name);
}

void    HumanA::setname(std::string name)
{
    this->name = name;
}
Weapon HumanA::getWeapon(void)
{
    return(this->weapon);
}

void    HumanA::setWeapon(Weapon name)
{
    this->weapon = name;
}

void    HumanA::attack()
{
    std::cout << this->name;
    std::cout << " attacks with their ";
    std::cout << this->weapon.getType() << std::endl;
}

HumanA::HumanA(std::string nam, Weapon& arma):weapon(arma),name(nam){}
