/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 18:30:39 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/27 21:11:34 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed GetSlopeBetweenPoints(Point const &one, Point const &two)
{
	Fixed slope;
	Fixed yDiff = two.getY() - one.getY();
	Fixed xDiff = two.getX() - one.getX();

	if (yDiff.getRawBits() == 0 || xDiff.getRawBits() == 0)
		return (slope);
	slope = yDiff / xDiff;
	return (slope);
}

Fixed GetConstant(Point const &one, Fixed &slope)
{
	Fixed constant;
	if (slope.getRawBits() == 0)
		return (constant);
	constant = one.getY() - (slope * one.getX());
	return (constant);
}

bool EvaluateWhichSide(Fixed &m, Fixed &c, Point const &third, Point const &point)
{
	Fixed thirdY_onLine = ((m * third.getX()) + c);
	Fixed pointY_onLine = ((m * point.getX()) + c);

	//std::cout << "third y on line: " << thirdY_onLine << " third y: " << third.getY() << std::endl;
	//std::cout << "point y on line: " << pointY_onLine << " point y: " << point.getY() << std::endl;
	if (pointY_onLine == point.getY())
		return (false);
	if (thirdY_onLine > third.getY() && pointY_onLine > point.getY())
		return (true);
	if (thirdY_onLine < third.getY() && pointY_onLine < point.getY())
		return (true);
	return (false);
}

bool EvaluateSideConst(Point const &one, Point const &two, Point const &third, Point const &point)
{
	if (one.getX() == two.getX())
	{
		if (third.getX() < one.getX() && point.getX() < one.getX())
			return (true);
		if (third.getX() > one.getX() && point.getX() > one.getX())
			return (true);
	}
	else if (one.getY() == two.getY())
	{
		if (third.getY() < one.getY() && point.getY() < one.getY())
			return (true);
		if (third.getY() > one.getY() && point.getY() > one.getY())
			return (true);
	}
	return (false);
}


bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	//std::cout << "a: "<< a.getX() << " " << a.getY() << " b: " << b.getX() << " " << b.getY() << " c: " << c.getX() << " " << c.getY() << std::endl;
	if (b == c || a == c || a == b)
	{
		return (false);
	}
	if (point == a || point == b || point == c)
		return (false);
	Fixed M_ab = GetSlopeBetweenPoints(a, b);
	Fixed M_ac = GetSlopeBetweenPoints(a, c);
	Fixed M_bc = GetSlopeBetweenPoints(b, c);

	if (M_ab == M_ac || M_ab == M_bc || M_ac == M_bc)
	{
		if (M_ab.getRawBits() != 0 && M_ac.getRawBits() != 0 && M_bc.getRawBits() != 0)
			return (false);
		if (M_ab.getRawBits() == 0 && M_ac.getRawBits() == 0 && M_bc.getRawBits() == 0)
			return (false);
	}

	Fixed C_ab = GetConstant(a, M_ab);
	Fixed C_ac = GetConstant(a, M_ac);
	Fixed C_bc = GetConstant(b, M_bc);

	if (M_ab.getRawBits() == 0)
	{
		if (!EvaluateSideConst(a,b,c,point))
			return (false);
	}
	else
	{
		if (!EvaluateWhichSide(M_ab, C_ab, c, point))
			return (false);
	}

	if (M_ac.getRawBits() == 0)
	{
		if (!EvaluateSideConst(a,c,b,point))
			return (false);
	}
	else
	{
		if (!EvaluateWhichSide(M_ac, C_ac, b, point))
			return (false);
	}

	if (M_bc.getRawBits() == 0)
	{
		if (!EvaluateSideConst(b,c,a,point))
			return (false);
	}
	else
	{
		if (!EvaluateWhichSide(M_bc, C_bc, a, point))
			return (false);
	}
	//std::cout << "trollex" << std::endl;

	return (true);
}
