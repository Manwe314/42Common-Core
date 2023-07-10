/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:26:11 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 19:39:44 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon()
{
	std::cout << this->_type << " broke 🗡️" << std::endl;
}

void Weapon::set_type(std::string type)
{
	this->_type = type;
}

std::string Weapon::get_type() const
{
	return(this->_type);
}
