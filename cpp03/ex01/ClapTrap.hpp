/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:48:06 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/11 14:20:49 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>


class ClapTrap
{
protected:
    std::string	name;
    int Hit_points;
    int Energy_points;
    int Attack_damage;
public:
    void attack( std::string const &target);
    void takeDamange(unsigned int amount);
    void beRepaired(unsigned int amount);
    int get_Hp(void) const;
    int get_Ep(void) const;
    int get_Ad(void) const;
    std::string get_name(void) const;
    void set_Hp(const unsigned int Hit_points);
    void set_Ep(const unsigned int Energy_points); 
    void set_Ad(const unsigned int Attack_damage); 
    ClapTrap();
    void operator = (const ClapTrap &Trap);
    ClapTrap(std::string const _name);
    ClapTrap(const ClapTrap &Trap);
    ~ClapTrap();
};

#endif