/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flaviobiondo <flaviobiondo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:18:19 by flaviobiond       #+#    #+#             */
/*   Updated: 2024/01/10 16:10:51 by flaviobiond      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
const int	Fixed::_bits = 8;

Fixed::Fixed() {
	// std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value) {
	// std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value) {
	// std::cout << "Float constructor called" << std::endl;
	_value = (int)(roundf(value * (1 << _bits)));
}

Fixed::Fixed(const Fixed& obj) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::~Fixed(void) {
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& obj) {
	// std::cout << "Assignation operator called" << std::endl;
	_value = obj.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	_value = raw;
}

int Fixed::toInt(void) const {
	return _value >> _bits;
}

float Fixed::toFloat(void) const {
	return (float)_value / (float)(1 << _bits);
}

std::ostream& operator<<(std::ostream& output, const Fixed& obj) {
	output << obj.toFloat();
	return output;
}

bool Fixed::operator>(const Fixed& fixed) {
	if (_value > fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(const Fixed& fixed) {
	if (_value < fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(const Fixed& fixed) {
	if (_value >= fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(const Fixed& fixed) {
	if (_value <= fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator==(const Fixed& fixed) {
	if (_value == fixed.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(const Fixed& fixed) {
	if (_value != fixed.getRawBits())
		return true;
	return false;
}

Fixed Fixed::operator+(const Fixed& fixed) {
	return(Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed& fixed) {
	return(Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed& fixed) {
	return(Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed& fixed) {
	return(Fixed(this->toFloat() / fixed.toFloat()));
}

// Post-increment
Fixed Fixed::operator++(int){
	Fixed	fix(*this);
	this->_value++;
	return (fix);
}


// Pre-increment
Fixed &Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

// Post-increment
Fixed Fixed::operator--(int){
	Fixed	fix(*this);
	this->_value--;
	return (fix);
}

// Pre-increment
Fixed Fixed::operator++(void){
	this->_value++;
	return (*this);
}