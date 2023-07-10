/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:06:09 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/29 22:35:35 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap a("Brown");
	ScavTrap b(a);

	a.takeDamage(5);
	a.attack("holly");
	a.beRepaired(14);
	a.guardGate();
}
