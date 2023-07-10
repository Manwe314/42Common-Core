/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:13:11 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/22 21:24:13 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie* zombie_one = newZombie("bob");
	randomChump("terry");
	zombie_one->announce();
	delete zombie_one;
	return (0);
}
