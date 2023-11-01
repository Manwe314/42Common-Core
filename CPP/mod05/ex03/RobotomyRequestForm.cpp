/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:17:34 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 18:25:37 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), _target(copy._target) {}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "robotomy request form shreded" << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeExecMin())
        throw AForm::GradeTooLowException();
    static int i;
    if (i % 2 == 0)
    {
        std::cout << "BZZZZ *Robotic noises* BZZZ " << _target << " has been succsesfully Robotized!" << std::endl;
    }
    else
    {
        std::cout << "BZZZZ *Robotic noises* BZZZ " << _target << " remains unrobotized :( " << std::endl;
    }
    i++;
}