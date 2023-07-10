/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:53:45 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/23 16:26:55 by lkukhale         ###   ########.fr       */
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
	Zombie(std::string name);
	Zombie( void );
	~Zombie();

	Zombie* zombieHorde(int N, std::string name);
	void announce( void );
	void set_name(std::string n);
};

#endif
