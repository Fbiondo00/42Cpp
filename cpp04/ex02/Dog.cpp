/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:11 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 16:25:30 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog (void): Animal("dog")
{
    this->brain = new Brain();
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
    std::cout << this->getType() << " bauuuwww"<<std::endl;
    return ;
}

Brain&	Dog::getBrain() const
{
	return(*(this->brain));
}

Dog&  Dog::operator=(Dog const &dog)
{
    if(this != &dog)
    {
        std::cout << dog.getType() << " in operator =" << std::endl;
        this->typ = dog.getType();
    }
    (this->brain) = &dog.getBrain();
    return *(this);
}