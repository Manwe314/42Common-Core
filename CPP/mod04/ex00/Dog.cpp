/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:27:14 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/07 17:41:32 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << _type <<  " Derived constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << _type <<  " Derived deconstructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "WOOF 🐶" << std::endl;
}
