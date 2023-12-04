/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:19:36 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/04 23:19:39 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int ac, char **av)
{
    int i;
    int y;
    
    if(ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        i = 0;
        while(++i < ac)
        {
            y = -1;
            while(av[i][++y])
            {
                if(av[i][y] > 96 && av[i][y] < 123)
                    std::cout << (char)(av[i][y] - 32);
                else
                std::cout << av[i][y];
            }
        }
    }
    std::cout << std::endl;
    return(0);
}