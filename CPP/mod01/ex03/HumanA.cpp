/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:45:03 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/23 19:08:36 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{
	this->_name = name;
}

HumanA::~HumanA()
{
	std::cout << this->_name << " has died ☠️" << std::endl;
}

void HumanA::attack()
{
	std::cout << this->_name << " attacks with " << this->_weapon.get_type() << " ⚔️" << std::endl;
}
