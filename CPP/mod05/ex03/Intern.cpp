/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:56:03 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 21:40:27 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "a free worker intern has joined the fight" << std::endl;
}

Intern::Intern(const Intern& copy)
{
    *this = copy;
}

Intern::~Intern()
{
    std::cout << "master gave intern a salary, intern is free now" << std::endl;
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* form;
    int casse = -1;
    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
            casse = i;
    }
    switch (casse)
    {
    case 0:
        std::cout << "Intern creates " << name << std::endl;
        form = new ShrubberyCreationForm(target);
        break;
    case 1:
        std::cout << "Intern creates " << name << std::endl;
        form = new RobotomyRequestForm(target);
        break;
    case 2:
        std::cout << "Intern creates " << name << std::endl;
        form = new PresidentialPardonForm(target);
        break;
    default:
        std::cout << "can not create " << name << ". form does not exist" << std::endl;
        form = 0;
        break;
    }
    return form;
}