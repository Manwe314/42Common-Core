/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:24:06 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/07 17:41:27 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << _type << " Derived construcor called" << std::endl;
}
Cat::~Cat()
{
	std::cout << _type << " Derived deconstrucor called" << std::endl;
}
void Cat::makeSound() const
{
	std::cout << "MEOW 🐱" << std::endl;
}
