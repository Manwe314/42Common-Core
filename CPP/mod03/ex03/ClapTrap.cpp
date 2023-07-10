/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:06:13 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/29 22:35:55 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NULL"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "default constructor" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "the name has been given" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) : name(copy.getName())
{
	hitPoints = copy.getHP();
	energyPoints = copy.getEnergy();
	attackDamage = copy.getAttack();
	std::cout << "copy constructor" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	if (this != &copy)
	{
		hitPoints = copy.getHP();
		energyPoints = copy.getEnergy();
		attackDamage = copy.getAttack();
	}
	return (*this);
}

std::string ClapTrap::getName() const
{
	return (this->name);
}

int ClapTrap::getHP() const
{
	return (this->hitPoints);
}

int ClapTrap::getEnergy() const
{
	return (this->energyPoints);
}

int ClapTrap::getAttack() const
{
	return (this->attackDamage);
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is exhausted 🥵" << std::endl;
		return ;
	}
	if (hitPoints != 0)
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << this->attackDamage << " points of Damage 😈"  << std::endl;
		energyPoints--;
	}
	else
		std::cout << "ClapTrap " << name << " Cannot attack they are dead, repair them first 🙃" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount < (unsigned int)hitPoints)
	{
		std::cout << "ClapTrap " << name << " got hit and took " << amount << ", Damage! 🤕" << std::endl;
		hitPoints -= amount;
	}
	else if (hitPoints != 0)
	{
		std::cout << "ClapTrap " << name << " got hit and took " << hitPoints << ", Damage and has died 😵" << std::endl;
		hitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << name << " is already DEAD 😇" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is exhausted 🥵" << std::endl;
		return ;
	}
	if (hitPoints >= 100)
		std::cout << "ClapTrap " << name << " is already at full health 🤤" << std::endl;
	else
	{
		if ((amount + hitPoints) > 100)
		{
			std::cout << "ClapTrap " << name << " Repairs itself and heals " << (100 - hitPoints) << " Hit Points 😍" << std::endl;
			hitPoints = 10;
		}
		else
		{
			std::cout << "ClapTrap " << name << " Repairs itself and heals " << amount << " Hit Points 🥰" << std::endl;
			hitPoints += amount;
		}
		energyPoints--;
	}

}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap OUT!" << std::endl;
}
