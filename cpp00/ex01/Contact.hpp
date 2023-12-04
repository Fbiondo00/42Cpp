/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:19:59 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/04 23:20:02 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		     size_t	getIndex(void) const;
	private:
		int			i;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
};

#endif