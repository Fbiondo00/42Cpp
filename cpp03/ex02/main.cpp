/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 21:47:24 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/11 14:16:41 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{

    ClapTrap	a;
	ClapTrap	b("Eugenio");
	ScavTrap	c("Ernesto");

	a.attack(b.get_name());
	b.takeDamange(a.get_Ad());
	a.beRepaired(15);

	c.attack(b.get_name());
	b.takeDamange(c.get_Ad());
	c.guardGate();

	return (0);
}