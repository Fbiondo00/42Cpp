/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:34:31 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 15:46:29 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal void constructor called"  << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &mal)
{
	std::cout  << "WrongAnimal copy constructor called"  << std::endl;
	(*this) = mal;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::operator = (WrongAnimal const &mal)
{
	this->type = mal.getType();
    return ;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::setType(std::string type)
{
    this->type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal doesn't sound!" << std::endl;
}
