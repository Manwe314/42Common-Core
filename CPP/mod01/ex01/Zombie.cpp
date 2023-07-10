/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:04:31 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/23 16:52:26 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie()
{
	this->name = "unknown";
}

Zombie::~Zombie()
{
	std::cout << this->name << " has died a second time RIP in peace" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiiinnnnnnzzzzzzzZ" << std::endl;
}

void Zombie::set_name(std::string n)
{
	this->name = n;
}
