/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:55:42 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/06 18:50:26 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <cctype>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>
# include <sstream>

class Zombie {
     std::string name;
    public:
        void set_name(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif