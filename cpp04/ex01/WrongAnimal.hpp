/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:20:44 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 15:38:23 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &mal);
		virtual ~WrongAnimal();
		
		virtual void makeSound() const;
		
		std::string getType() const;
		void setType(std::string type); 

		void	operator = (WrongAnimal const &mal);

	protected:
		std::string type;
};

