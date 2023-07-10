/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:55:12 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/23 19:08:30 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB()
{
	std::cout << this->_name << " has died ☠️" << std::endl;
}

void HumanB::attack()
{
	std::cout << this->_name << " attacks with " << this->_weapon->get_type() << " ⚔️" << std::endl;
}

void HumanB::set_weapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
