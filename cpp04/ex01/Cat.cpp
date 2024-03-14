/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:02 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 15:45:58 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat (void): Animal("cat")
{
    this->brain = new Brain();
    std::cout << "Cat Default costructor called" << std::endl;
    return ;
}

Cat::Cat (Cat const &cat): Animal()
{
    std::cout << "Cat Copy costructor called" << std::endl;
    this->brain = new Brain();
    *this = cat;
    return ;
}

Cat::~Cat (void)
{
    delete  this->brain;
    std::cout << "Cat Default distructor called" << std::endl;
    return ;
}


Cat&  Cat::operator=(Cat const &cat)
{
    if(this != &cat)
    {
        std::cout << cat.getType() << " in operator =" << std::endl;
        this->typ = cat.getType();
    }
    *(this->brain) = cat.getBrain();
    return *(this);
}


void Cat::makeSound(void) const
{
    std::cout << this->getType() << " miaowwww" << std::endl;
    return ;
}

Brain&	Cat::getBrain() const
{
	return(*(this->brain));
}
