/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:20:17 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/21 16:43:33 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int PhoneBook::number_contact= 0;

void PhoneBook::addContact()
{
    Contact newContact;
    
    number_contact++;
    
    index = number_contact % 8;
    newContact.createContact(index);
	_list[index] = newContact;
}


void printcontact(Contact _list[], int number_contact )
{
    for(int i = 0; i <= number_contact && i < 8; i++){
        std::cout << '|' << std::right << std::setw(10) << _list[i].getIndex();
        _list[i].print();
    }
}

void printTable1(Contact _list[], int i)
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    printcontact(_list, i);
    std::cout << "---------------------------------------------" << std::endl;
}
int stringToInt(const std::string& str)
{
	int nb = 0;

	std::istringstream(str) >> nb;

	return nb;
}

void PhoneBook::searchContact()
{
    std::string cmd;
    int i = 0;
    bool		is_valid = false;


    if(number_contact == 0)
    {
        std::cout << "Contact not found :( " << std::endl;
        return ;
    }
    printTable1(_list, number_contact);
    clearerr(stdin);
		std::cin.clear();
        std::cout << "$> Index ";
        while(!is_valid){
         std::getline(std::cin, cmd) ;
        i = stringToInt(cmd);
        if (i < 1 || number_contact < i) {
			std::cout << "Invalid index." << std::endl;
			std::cout << "Index: ";
        }
        else
            is_valid = true;
    }
    _list[i].ContactInfo();
}