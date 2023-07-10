/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:06 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 15:07:51 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << _type << " Derived construcor called" << std::endl;
	try
	{
		_brain = new Brain();
	}
	catch (const std::bad_alloc& error)
	{
		std::cout << "Memory allocation has failed: " << error.what() << std::endl;
	}
}

Cat::~Cat()
{
	std::cout << _type << " Derived deconstrucor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &copy)
{
	std::cout << _type << " copy constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << _type << " opertator overload called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "MEOW 🐱" << std::endl;
}

