/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:13 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/14 14:25:16 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"

class Dog: public Animal
{
    public:
    Dog();
    Dog(Dog const &cat);
    Dog(std::string type);
    ~Dog();
    Dog& operator=(Dog const &dog);
    void	makeSound(void) const;
};

#endif