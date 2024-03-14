/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:13 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 15:41:40 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
    public:
    Dog();
    Dog(Dog const &cat);
    ~Dog();
    void	makeSound(void) const;
    Dog& operator=(Dog const &dog);
    Brain&		getBrain() const;
    private:
    Brain *brain;
};

#endif