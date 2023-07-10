/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:26:12 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 18:51:53 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _value;
	static const int _nbFractionalBits;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &copy);
	Fixed &operator=(Fixed const &copy);
	void setRawBits(int const raw);
	int getRawBits( void ) const;
};

#endif

