/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:10:46 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/10 22:07:55 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

std::string const &Weapon::getType(void){
    return (this->type);
}

void    Weapon::setType(std::string new_str)
{
       this->type = new_str;
       
}

Weapon::Weapon(std::string name):type(name){}