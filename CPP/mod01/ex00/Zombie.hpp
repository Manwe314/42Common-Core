/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:53:45 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/22 21:24:12 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include<string>
#include<iostream>

class Zombie
{
private:
	std::string name;

public:
	void announce(void);
	Zombie(std::string name);
	~Zombie();
};


void randomChump(std::string name);
Zombie* newZombie(std::string name);


#endif
