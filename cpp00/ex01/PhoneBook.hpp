#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include "Contact.hpp"
# include <iomanip>
# include <cstdlib>
# include <cctype>

class PhoneBook
{
    public:
        void    addContact();
    private:
        Contact _list[8];
        int     index;
        int number_contact;
};

#endif