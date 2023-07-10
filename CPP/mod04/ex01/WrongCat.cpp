/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 17:34:49 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/07 17:41:44 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << _type << " Derived construcor called" << std::endl;
}
WrongCat::~WrongCat()
{
	std::cout << _type << " Derived deconstrucor called" << std::endl;
}
void WrongCat::makeSound() const
{
	std::cout << "MEOW 🦁" << std::endl;
}
