/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:49:41 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/30 20:07:13 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "{Frag Trap} " << name << ", Constucted" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "{Frag Trap} " << name << ", DEconstructed" << std::endl;

}

void FragTrap::highFivesGuys()
{
	std::cout << "{Frag Trap} " << name << ", wants to high five you guys 🖐" << std::endl;
}
