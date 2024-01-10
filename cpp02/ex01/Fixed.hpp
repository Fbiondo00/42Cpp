/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:45:02 by flaviobiond       #+#    #+#             */
/*   Updated: 2023/12/29 21:37:14 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include <string>

class Fixed {
	public:
		Fixed(const Fixed& obj);
        Fixed(const int value);
		Fixed(const float value);
        Fixed();
		~Fixed();
        
		Fixed& operator=(const Fixed& obj);

        int toInt(void) const;
		float toFloat(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	_value;
		static const int _bits;
};
std::ostream& operator<<(std::ostream& output, const Fixed& obj);
