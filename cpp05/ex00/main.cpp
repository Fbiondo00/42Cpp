/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:39:02 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/12/24 15:41:35 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat c2("Carlo", 3);
		Bureaucrat c1("Piero", 1);
		Bureaucrat base;


		std::cout<<c2;
		std::cout<<base;
		std::cout<<c1;
	}
	catch (const std::exception& e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return (0);
}
