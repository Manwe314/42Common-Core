/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:45:49 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/30 20:08:13 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
	this->name = name;
	this->ClapTrap::name = name + "_ClapTrap";

	FragTrap::hitPoints = 100;
	ScavTrap::energyPoints = 50;
	FragTrap::attackDamage =30;

	std::cout << "🔷 Diamond Trap 🔷 " << name << ", is constructed" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "🔷 Diamond Trap 🔷 " << name << ", is DEconstructed" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "HI im 🔷 Diamond trap named: " << name << " and my Clappy name is: " << this->ClapTrap::name << std::endl;
}
