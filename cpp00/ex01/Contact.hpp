#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <stdlib.h>
# include <sstream>


class Contact {
	public:
		void 		ContactInfo(void);
		void		createContact(int i);
		void		print(void);
	private:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif