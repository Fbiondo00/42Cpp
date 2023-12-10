/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:10:30 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/10 22:29:22 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"


class HumanA{
    Weapon& weapon;
    std::string name;
    public:
    HumanA(std::string name, Weapon& arma);
    void    attack(void);
    std::string   getname(void);
    void           setname(std::string new_str);
    Weapon          getWeapon(void);
    void            setWeapon(Weapon name);
    
};

#endif