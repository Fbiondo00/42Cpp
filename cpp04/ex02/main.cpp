/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:39:27 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/15 16:02:38 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)

{
	Animal *j= new Cat;
	Animal	*giungla[10];
	Cat		cat;
	Cat		another_cat = cat;
	Dog		dog;
	Dog		another_dog = dog;

	dog.makeSound();
	j->makeSound();

	for (int i = 0; i < 5; i++)
		giungla[i] = new Cat();
	
	for (int i = 5; i < 10; i++)
		giungla[i] = new Dog();

	for (int i = 0; i < 10; i++)
		delete giungla[i];

	return (0);
}