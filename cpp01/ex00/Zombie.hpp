/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:30:54 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/05 19:47:57 by flaviobiond      ###   ########.fr       */
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
        // Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
    
#endif
