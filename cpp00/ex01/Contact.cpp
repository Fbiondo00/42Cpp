
#include "Contact.hpp"

//  Questa funzione viene utilizzata per leggere 
//  una riga dallo stream di input (std::cin)
//   e memorizzarla nella variabile specificata
// std::cin >> std::ws: 
// Questa parte utilizza l'operatore >> per estrarre 
// l'input dalla standard input (std::cin). 
// std::ws è un manipolatore utilizzato per ignorare 
// eventuali spazi bianchi iniziali o \n. 
void Contact::createContact(int i) {
	index = i;
	std::cout << "First name: ";
	std::getline(std::cin >> std::ws, first_name);
	std::cout << "Last name: ";
	std::getline(std::cin >> std::ws, last_name);
	std::cout << "Nickname: ";
	std::getline(std::cin >> std::ws, nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin >> std::ws, phone_number);
	std::cout << "Darkar is secret: ";
	std::getline(std::cin >> std::ws, darkis_secret);
}

