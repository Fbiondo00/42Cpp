/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 21:18:09 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/26 21:30:26 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl Harl;
    
    if(ac != 2)
        std::cerr << "Invalid argouments" << std::endl;
    else
        {
        std::string set = av[1];
        if(!set.compare("DEBUG") || !set.compare("ERROR") 
                || !set.compare("INFO") || !set.compare("WARNING"))
                    Harl.complain(set);
        else
                std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

                    
        }
}