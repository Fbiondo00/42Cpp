/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:20:26 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/04 23:20:28 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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