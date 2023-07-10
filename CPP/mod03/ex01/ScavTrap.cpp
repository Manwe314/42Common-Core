/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 20:58:38 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/29 22:36:18 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "Scav Trap constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Scav Trap deconstructor" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "Scav Trap " << name << " is exhausted 🥵" << std::endl;
		return ;
	}
	if (hitPoints != 0)
	{
		std::cout << "Scav Trap " << name << " attacks " << target << " with a 🗡, causing " << this->attackDamage << " points of Damage 👹"  << std::endl;
		energyPoints--;
	}
	else
		std::cout << "Scav Trap " << name << " Cannot attack they are dead, repair them first 🤭" << std::endl;

}

void ScavTrap::guardGate()
{
	if (energyPoints <= 0)
	{
		std::cout << "Scav Trap " << name << " is exhausted 🥵" << std::endl;
		return ;
	}
	std::cout << "Scav Trap " << name << ", has entered the gatekeeper mode 💂🏻‍♀️" << std::endl;
}
