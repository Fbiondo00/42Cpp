/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:55:40 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/06 18:41:57 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *orgia = new Zombie[N];
    int i = -1;
    while(++i < N)
     orgia[i].set_name(name);  
    return(orgia);
}

