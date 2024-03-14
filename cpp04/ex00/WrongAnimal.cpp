/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:34:31 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/14 14:31:03 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal")
{
	std::cout << "WrongAnimal void constructor called"  << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "WrongAnimal type constructor called" <<std::endl;
    this->type = type;
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


std::string WrongAnimal::getType() const
{
    return (this->type);
}

void WrongAnimal::setType(std::string typ)
{
    this->type = typ;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal doesn't sound!" << std::endl;
}

WrongAnimal&  WrongAnimal::operator=(WrongAnimal const &dog)
{
    if(this != &dog)
    {
        std::cout << dog.getType() << " in operator =" << std::endl;
        this->type = dog.getType();
    }
    return *(this);
}