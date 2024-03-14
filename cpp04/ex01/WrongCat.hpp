/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:20:38 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/03/13 16:02:51 by flaviobiond      ###   ########.fr       */
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
		WrongCat(WrongCat const &c); // copy constructor
		~WrongCat(); // destructor
		WrongCat& operator=(WrongCat const &wrongcat);
		void	makeSound(void) const;
};