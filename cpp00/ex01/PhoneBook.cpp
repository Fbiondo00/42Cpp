#include "PhoneBook.hpp"

void PhoneBook::addContact()
{
    Contact newContact;
    
    number_contact++;
    index = number_contact % 8;

    newContact.createContact(index);
	_list[index] = newContact;
    

    // std::cout << contact_list[index] << " ";

}