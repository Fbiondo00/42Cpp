/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:09:09 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 15:41:02 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    public:
    Cat();
    Cat(Cat const &cat);
    ~Cat();
    Cat& operator=(Cat const &cat);
    void	makeSound(void) const;
    Brain&		getBrain() const;
    private:
    Brain *brain;
};

#endif