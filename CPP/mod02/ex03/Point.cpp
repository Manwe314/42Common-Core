/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:13:15 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/27 20:46:20 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	std::cout << "default constructor point" << std::endl;

}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y)
{
	//std::cout << "parametre constructor point" << std::endl;
	//std::cout << "X~ number " << _x << std::endl;
	//std::cout << "Y~ number " << _y << std::endl;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	//std::cout << "parametre constructor point" << std::endl;
	//std::cout << "X~ number " << _x << std::endl;
	//std::cout << "Y~ number " << _y << std::endl;
}


Point::Point(const int x, const int y) : _x(x), _y(y)
{
	//std::cout << "parametre constructor point" << std::endl;
	//std::cout << "X~ number " << _x << std::endl;
	//std::cout << "Y~ number " << _y << std::endl;
}

Point::Point(const Point &pont)
{
	*this = pont;
}

Point &Point::operator=(const Point &pont)
{
	if (this != &pont)
	{
		(Fixed)Point::_x = pont.getX();
		(Fixed)Point::_y = pont.getY();
	}
	return (*this);
}

Point::~Point()
{
	//std::cout << "destructor point " << std::endl;
}

Fixed Point::getX() const
{
	return(_x);
}

Fixed Point::getY() const
{
	return(_y);
}

bool Point::operator==(Point const &other) const
{
	//std::cout << "X~ this: " << this->_x << " other: " << other.getX() << std::endl;
	//std::cout << "Y~ this: " << this->_y << " other: " << other.getY() << std::endl;
	if (this->getX() == other.getX() && this->getY() == other.getY())
		return (true);
	return (false);

}
