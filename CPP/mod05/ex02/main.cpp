/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:43:26 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 19:32:39 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat j("Jose", 150);
    ShrubberyCreationForm f1("home");
    RobotomyRequestForm f2("beth");
    PresidentialPardonForm f3("goty");
    
    j.signForm(f1);
    j.signForm(f2);
    j.signForm(f3);

    j.increment(149);

    j.signForm(f1);
    j.signForm(f2);

    j.executeForm(f1);
    j.executeForm(f2);

    j.decrement(10);

    j.executeForm(f3);

    j.increment(8);
    
    j.executeForm(f3);
}
