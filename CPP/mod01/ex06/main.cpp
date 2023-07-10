/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:05:05 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/24 16:38:03 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int get_case_id(std::string input)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (input == levels[i])
		{
			return (i);
		}
	}
	return (-1);

}

int main(int argc, char *argv[])
{
	Harl harold;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about something stupid ]" << std::endl;
		return (0);
	}

	switch (get_case_id(argv[1]))
	{
	case 0:
			harold.complain("DEBUG");
	case 1:
			harold.complain("INFO");
	case 2:
			harold.complain("WARNING");
	case 3:
			harold.complain("ERROR");
			break;
	default:
		std::cout << "[ Probably complaining about something stupid ]" << std::endl;
	}

	return (0);
}
