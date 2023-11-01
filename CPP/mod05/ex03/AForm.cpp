/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:20:18 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 19:31:33 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _grade_sign_min(150), _grade_exec_min(150)
{
    _is_signed = false;
    std::cout << "default form made" << std::endl;
}

AForm::AForm(std::string name, int grade_sign_min, int grade_exec_min) : _name(name), _grade_sign_min(grade_sign_min), _grade_exec_min(grade_exec_min)
{
    _is_signed = false;
    std::cout << "Form " << name << " created" << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy.getName()),_grade_sign_min(copy.getGradeSignMin()), _grade_exec_min(copy.getGradeExecMin()), _is_signed(copy.getIsSigned())
{
    std::cout << "Copy constructor!" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        this->_is_signed = other.getIsSigned();
    return (*this);
}

AForm::~AForm()
{
    std::cout << "Form " << this->getName() << " shreded" << std::endl;
}

std::string AForm::getName() const
{
    return (this->_name);
}
int AForm::getGradeSignMin() const
{
    return (this->_grade_sign_min);
}
int AForm::getGradeExecMin() const
{
    return (this->_grade_exec_min);
}
bool AForm::getIsSigned() const
{
    return (this->_is_signed);
}

void AForm::beSigned(Bureaucrat& buro)
{
    int min = this->getGradeSignMin();
    if (min < buro.getGrade())
        throw AForm::GradeTooLowException();
    else
        this->_is_signed = true;
}

std::ostream& operator<<(std::ostream& obj, AForm const &form)
{
    obj << "from " << form.getName() << "minimum grade to sign " << form.getGradeSignMin() << " minumum grade to execute " << form.getGradeExecMin() << " current signed status " << form.getIsSigned() << std::endl;
    return (obj);
}