/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:29:46 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/27 20:43:12 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;
public:
	Point();
	Point(Fixed const &x, Fixed const &y);
	Point(const float x, const float y);
	Point(const int x, const int y);
	Point(const Point &pont);
	Point & operator=(const Point &pont);
	~Point();

	bool operator==(Point const &other) const;

	Fixed  getX( void ) const;
	Fixed  getY( void ) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
