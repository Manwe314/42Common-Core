/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:26:23 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 18:38:01 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentalPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), _target(copy._target) {}

PresidentialPardonForm::~PresidentialPardonForm() 
{
    std::cout << "Presidental Pardon Form shreded" << std::endl;
}

void PresidentialPardonForm::execute( const Bureaucrat& executor) const
{
    if (this->getIsSigned() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeExecMin())
        throw AForm::GradeTooLowException();
    std::cout << _target << " ha been pardoned by Zaphod Beeblebrox" << std::endl;
}
