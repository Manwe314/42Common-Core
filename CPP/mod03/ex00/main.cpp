/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:06:09 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/29 20:07:54 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap george("george");
	ClapTrap z;
	ClapTrap geo(george);
	ClapTrap boby("boby");

	z = george;

	z.takeDamage(7);

	george.attack("boby");

	boby.takeDamage(5);

	boby.attack("george");

	george.takeDamage(12);

	boby.beRepaired(8);

	boby.beRepaired(10);

	george.attack("boby");
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.beRepaired(1);
	george.attack("boby");
	geo.takeDamage(100);
}
