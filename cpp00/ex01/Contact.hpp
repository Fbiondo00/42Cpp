#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>


class Contact {
	public:
		void		createContact(int i);
	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkis_secret;
};

#endif