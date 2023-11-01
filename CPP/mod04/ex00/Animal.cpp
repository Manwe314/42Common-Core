/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:07:17 by lkukhale          #+#    #+#             */
/*   Updated: 2023/10/06 16:49:26 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Animal")
{
	std::cout << _type << " Base constructor called" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << _type << " Base constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	*this = copy;
	std::cout << "Base copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Base = operator overload called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "Base deconstructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "*Generic Animal Sounds*" << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
