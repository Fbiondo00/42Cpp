/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:06 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/15 16:03:49 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void): typ("Animals")
{
    std::cout << " Animal Default constructor called" << std::endl;
    return ;
}
Animal::Animal(std::string animal): typ(animal)
{
    std::cout << " Animal String constructor called" << std::endl;
    return ;
}
Animal::Animal(Animal const &animal)
{
    std::cout << " Animal Copy constructor called" << std::endl;
    *this = animal;
    return ;
}

Animal::~Animal(void)
{
	std::cout << "Animal default destructor called"  << std::endl;
	return ;
}

void Animal::operator=(Animal const &animal)
{
    this->typ = animal.getType();
    std::cout << animal.getType() << " in operator =" << std::endl;
    return ;
}

std::string Animal::getType(void) const
{
    return(this->typ);
}
