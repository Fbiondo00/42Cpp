/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:02:52 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/06 18:48:18 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "Zombie.hpp"

void Zombie::set_name(std::string name) {
	this->name = name;
}

void Zombie::announce(void)
{
   std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie(void) {
	std::cout << name << ": Oh shiiit" << std::endl;
}