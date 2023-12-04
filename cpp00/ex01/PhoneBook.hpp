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
        void    init();
        void    addContact();
        void    searchContact();
    private:
        int     index;
        Contact _list[8];
        static int number_contact;
};

#endif