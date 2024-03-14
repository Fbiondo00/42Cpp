/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:20:38 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/14 14:31:53 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <iomanip>
# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void); // void constructor
		WrongCat(std::string type); // string constructor
		WrongCat(WrongCat const &c); // copy constructor
		~WrongCat(); // destructor
		WrongCat& operator=(WrongCat const &wrongcat);
		void	makeSound(void) const;
};