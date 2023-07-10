/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:26:14 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 18:58:36 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main()
{

	if (bsp(Point(1.37f, 1.45f), Point(4.12f, 2.78f), Point(2.86f, 5.32f), Point(2.02f, 3.07f)))
	{
		std::cout << "the point is inside the given triangle" << std::endl;
	}
	else
	{
		std::cout << "the point is NOT inside the given triangle (if it even is a trinagle...)" << std::endl;
	}
	//bsp(Point(0.0f, 0.0f), Point(8.0f, 0.0f), Point(8.0f, 0.0f), Point(2.0f, 3.0f))
	//bsp(Point(4.0f, 5.0f), Point(8.0f, 3.0f), Point(6.0f, 7.0f), Point(120.0f, 35.0f))
	return 0;
}
