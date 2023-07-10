/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:26:10 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 18:52:26 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_nbFractionalBits = 8;

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed &Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assginment constructor called" << std::endl;
	if (this != &copy)
	{
		Fixed::_value = copy._value;
	}
	return(*this);
}

void Fixed::setRawBits(int const raw)
{
	_value = raw;
}


int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(_value);
}

Fixed::Fixed(const int num)
{
	_value = num << _nbFractionalBits;
}

Fixed::Fixed(const float fnum)
{
	_value = std::round(fnum * (1 << _nbFractionalBits));
}

int Fixed::toInt() const
{
	return(_value >> _nbFractionalBits);
}

float Fixed::toFloat() const
{
	return((float)_value / (float)(1 << _nbFractionalBits));
}

std::ostream &operator<<(std::ostream& obj, Fixed const &fixedNumber)
{
	obj << fixedNumber.toFloat();
	return obj;
}
