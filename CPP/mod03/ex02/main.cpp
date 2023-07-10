/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:06:09 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/30 16:23:51 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap a("Brown");
	FragTrap b(a);

	a.takeDamage(5);
	a.attack("holly");
	a.beRepaired(14);
	a.highFivesGuys();
}
