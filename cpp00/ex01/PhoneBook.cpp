#include "PhoneBook.hpp"

static  int number_contact;

void PhoneBook::addContact()
{
    Contact newContact;
    
    number_contact++;
    index = number_contact % 8;

    newContact.createContact(index);
	_list[index] = newContact;
}


void printcontact(Contact _list[])
{
    for(int i = 0; i <= number_contact; i++){
        _list[i].print();
    }
}

void printTable1(Contact _list[])
{
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    printcontact(_list);
}

void PhoneBook::searchContact()
{
    if(number_contact == 0)
    {
        std::cout << "0 Contact :( " << std::endl;
        return ;
    }
    printTable1(_list);
    std::cout << "1 Contact :) " << std::endl;
}