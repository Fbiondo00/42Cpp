#include "PhoneBook.hpp"


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
    // int i = 0;
    if (ac != 1)
		std::cout << "Too many arguments!" << std::endl;
    else 
    {   
    while (true)
    {        
        std::cout << "Please enter a command: (ADD, SEARCH, EXIT)" << std::endl;
        std::getline(std::cin, command) ;
        clearerr(stdin);
		std::cin.clear();
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
            // phoneBook.search();
        }
        else {
			std::cout << "Invalid cmd." << std::endl;
		}
    }
    }
    return (0);
}