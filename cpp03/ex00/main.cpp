/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:47:43 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/10 21:47:44 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("ciccio");
    ClapTrap b(a);
    ClapTrap c;

    c.attack(b.get_name());
    b.takeDamange(0);
    b.beRepaired(0);
}