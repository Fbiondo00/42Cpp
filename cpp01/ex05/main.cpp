/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:05:17 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/26 17:17:33 by flaviobiond      ###   ########.fr       */
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
                std::cerr << "syntax error" << std::endl;
                    
        }
}