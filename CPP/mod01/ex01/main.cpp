/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:13:11 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/23 16:55:58 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie zomb;
	Zombie* LEGION;
	LEGION = zomb.zombieHorde(5, "LEGIOOON");
	for (int i = 0; i < 5; i++)
	{
		LEGION[i].announce();
	}
	std::cout << std::endl;
	zomb.announce();

	delete[] LEGION;
	return (0);
}
