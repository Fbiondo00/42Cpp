#include "PhoneBook.hpp"

void PhoneBook::init()
{
    this->index = 0;
};

size_t	Contact::getIndex(void) const
{
	return (this->i);
};


// clearerr(stdin) è una funzione in stile C e 
// std::cin.clear() è un metodo della classe 
// std::basic_ios in C++, entrambe svolgono la funzione 
// di ripristinare lo stato di errore del rispettivo stream di input.
int main (int ac, char **av)
{
    (void)av;
    std::string command;
    PhoneBook phonebook;
    Contact newcontact;
    phonebook.init();
    if (ac != 1)
		std::cout << "Too many arguments!" << std::endl;
    else 
    {   
    while (42)
    {        
        std::cout << "(ADD, SEARCH, EXIT)" << std::endl;
        clearerr(stdin);
		std::cin.clear();
        std::cout << "$> ";
        std::getline(std::cin, command) ;
        if (command.compare("ADD") == 0)
        {
           phonebook.addContact();
        }
       else if (command.compare("EXIT") == 0)
        {
            break ;
        }
       else if (command.compare("SEARCH") == 0)
        {
            phonebook.searchContact();
        }
        else {
			std::cout << "Invalid cmd." << std::endl;
		}
    }
    }
    return (0);
}