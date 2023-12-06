/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:02:56 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/06 18:53:34 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main ()
{
    int x = 4;
    int i = -1;
    Zombie *orgia;

    orgia = zombieHorde(x, "dio");
    while(++i < x)
        orgia->announce(); 
    delete[] orgia;
}