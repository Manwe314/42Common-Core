/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:26:55 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 17:30:15 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << _type << " Base constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << _type << " Base constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy)
{
	*this = copy;
	std::cout << "Base copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "Base = operator overload called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Base deconstructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return _type;
}
