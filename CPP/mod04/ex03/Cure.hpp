/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:42:35 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 20:44:25 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP
#include "AMateria.hpp"

class Cure
{
public:
	Cure();
	Cure(const Cure& copy);
	Cure& operator=(const Cure& other);
	~Cure();
	AMateria* clone();
	void use(ICharacter& target);
};



#endif
