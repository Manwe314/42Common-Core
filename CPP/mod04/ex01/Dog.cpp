/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:27:14 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 15:17:14 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << _type <<  " Derived constructor called" << std::endl;
	try
	{
		_brain = new Brain();
	}
	catch(const std::bad_alloc& error)
	{
		std::cout << "Memory allocation has failed: " << error.what() << std::endl;
	}
}

Dog::~Dog()
{
	std::cout << _type <<  " Derived deconstructor called" << std::endl;
	delete _brain;
}

Dog::Dog (const Dog &copy)
{
	std::cout << _type << " Copy constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << _type << " opertator overload called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "WOOF 🐶" << std::endl;
}
