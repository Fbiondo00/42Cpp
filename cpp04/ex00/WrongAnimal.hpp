/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:20:44 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/14 14:30:00 by flaviobiond      ###   ########.fr       */
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
		WrongAnimal(std::string type);
		virtual ~WrongAnimal();
		
		void makeSound() const;
		
		std::string getType() const;
		void setType(std::string type); 

		WrongAnimal&	operator=(WrongAnimal const &mal);

	protected:
		std::string type;
};

