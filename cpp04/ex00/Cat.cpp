/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:02 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/15 15:39:37 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat (void): Animal("cat")
{
    std::cout << "Cat Default costructor called" << std::endl;
    return ;
}

Cat::Cat (Cat const &cat): Animal()
{
    std::cout << "Cat Copy costructor called" << std::endl;
    *this = cat;
    return ;
}

Cat&  Cat::operator=(Cat const &cat)
{
    if(this != &cat)
    {
        std::cout << cat.getType() << " in operator =" << std::endl;
        this->type = cat.getType();
    }
    return *(this);
}


Cat::~Cat (void)
{
    std::cout << "Cat Default distructor called" << std::endl;
    return ;
}

void Cat::makeSound(void) const
{
    std::cout <<  " miaowwww" << std::endl;
    return ;
}
