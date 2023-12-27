/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:19:49 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/19 16:41:22 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"

//  Questa funzione viene utilizzata per leggere 
//  una riga dallo stream di input (std::cin)
//   e memorizzarla nella variabile specificata
// std::cin >> std::ws: 
// Questa parte utilizza l'operatore >> per estrarre 
// l'input dalla standard input (std::cin). 
// std::ws è un manipolatore utilizzato per ignorare 
// eventuali spazi bianchi iniziali o \n. 
void Contact::createContact(int in) {
	i = in;
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, first_name);
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin >> std::ws, phone_number);
	std::cout << "Darkar is secret: ";
	std::getline(std::cin >> std::ws, darkest_secret);
}

void printContanct(std::string cont)
{
	std::string new_content;
	
	if(cont.length() > 10)
		new_content = cont.substr(0, 9) + '.';
	else
		new_content = cont;
	std::cout << '|' << std::right << std::setw(10) << new_content;

}

std::string intToString(int nb) {
	std::ostringstream ss;

	ss << nb;

	return ss.str();
};




void Contact::print(void) {
	printContanct(first_name);
	printContanct(last_name);
	printContanct(nickname);
	std::cout << '|' << std::endl;
}

void Contact::ContactInfo(void) {
	std::cout << "NOME " << first_name
		<< "COGNOME " << last_name << std::endl
		<< "nick è " << nickname << std::endl
		<< "Phone number: " << phone_number << std::endl
		<< "Darkest secret: " << darkest_secret << std::endl;
}
