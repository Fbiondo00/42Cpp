/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:18:37 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/10 21:05:09 by flaviobiond      ###   ########.fr       */
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

		Fixed operator+(const Fixed& fixed);
		Fixed operator-(const Fixed& fixed);
		Fixed operator*(const Fixed& fixed);
		Fixed operator/(const Fixed& fixed);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed& operator--(void);
		Fixed operator++(void);
		static Fixed const	&min(Fixed const &f1, Fixed const &f2);
		static Fixed &min(Fixed &f1, Fixed  &f2);
		static Fixed	&max(Fixed  &f1, Fixed  &f2);
		static Fixed const	&max(Fixed const &f1, Fixed const &f2);
		bool operator>(const Fixed& fixed) const;
		bool operator<(const Fixed& fixed) const;
		bool operator>=(const Fixed& fixed) const;
		bool operator<=(const Fixed& fixed) const;
		bool operator==(const Fixed& fixed) const;
		bool operator!=(const Fixed& fixed) const;
	private:
		int	_value;
		static const int _bits;
};

std::ostream& operator<<(std::ostream& output, const Fixed& obj);
