/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:11 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/14 14:35:54 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog (void): Animal("dog")
{
    std::cout << "Dog Default Costructor called" << std::endl;
    return ;
}

Dog::Dog (Dog const &dog): Animal(dog.getType())
{
    std::cout << "Dog Copy Costructor called" << std::endl;
    *this = dog;
    return ;
}

Dog::~Dog(void)
{
    std::cout << "Dog distructor called " << std::endl;
    return ;
}

void Dog::makeSound(void) const
{
    std::cout <<  " bauuuwww"<<std::endl;
    return ;
}

Dog&  Dog::operator=(Dog const &dog)
{
    if(this != &dog)
    {
        std::cout << dog.getType() << " in operator =" << std::endl;
        this->typ = dog.getType();
    }
    return *(this);
}