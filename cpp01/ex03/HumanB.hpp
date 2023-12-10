/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:10:35 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/10 22:40:18 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    Weapon  *weapon;
    std::string name;
    public:
    HumanB(std::string nam);
    void            attack(void);
    std::string     getName(void);
    void            setName(std::string new_str);
    Weapon*         getWeapon(void);
    void            setWeapon(Weapon &name);
    
};



#endif