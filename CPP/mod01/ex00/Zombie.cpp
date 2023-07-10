/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:04:31 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/22 21:24:21 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << this->name << " has died a second time RIP in peace" << std::endl;
}

void Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiiinnnnnnzzzzzzzZ" << std::endl;
}
