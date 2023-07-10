/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 21:05:05 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/23 21:25:24 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	Harl harold;

	harold.complain("DEBUG");
	harold.complain("INFO");
	harold.complain("WARNING");
	harold.complain("ERROR");
	return (0);
}
