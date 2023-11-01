/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:43:26 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 17:28:57 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat joe("Jose", 30);
    AForm one("S2", 40, 50);

    joe.signForm(one);

    joe.decrement(20);

    joe.signForm(one);
}