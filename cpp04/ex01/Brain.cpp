/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 15:32:03 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/12 15:41:52 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    int count = 100;
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; i < count; i++)
		this->id[i] = "lampadina";
	return ;
}

Brain::Brain(Brain const &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	(*this) = brain;
	return ;
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;
	return ;
}

void	Brain::operator = (Brain const &brain)
{
    int count = 100;
	for (int i = 0; i < count; i++)
		this->id[i] = brain.id[i];
	return ;
}

std::string const	*Brain::getIdeas(void) const
{
	return (this->id);
}
