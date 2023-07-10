/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:26:12 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/27 16:35:40 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _value;
	static const int _nbFractionalBits;
public:
	Fixed();
	Fixed(const int num);
	Fixed(const float fnum);
	~Fixed();
	Fixed(Fixed const &copy);
	Fixed &operator=(Fixed const &copy);

	bool operator<( Fixed const &other) const;
	bool operator>( Fixed const &other) const;
	bool operator<=( Fixed const &other) const;
	bool operator>=( Fixed const &other) const;
	bool operator==( Fixed const &other) const;
	bool operator!=( Fixed const &other) const;

	Fixed operator+( Fixed const &other) const;
	Fixed operator-( Fixed const &other) const;
	Fixed operator*( Fixed const &other) const;
	Fixed operator/( Fixed const &other) const;

	Fixed operator++( int );
	Fixed operator--( int );
	Fixed& operator++( void );
	Fixed& operator--( void );

    static const Fixed& max( const Fixed &a, const Fixed &b );
    static const Fixed& min( const Fixed &a, const Fixed &b );
    static Fixed& max( Fixed &a, Fixed &b );
	static Fixed& min( Fixed &a, Fixed &b );

	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
};

std::ostream& operator<<(std::ostream& obj, Fixed const &fixedNumber);


#endif

