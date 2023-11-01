/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:20:58 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 15:45:18 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Avarage joe"), _grade(150)
{
    std::cout << "an Avarage joe was created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
    if(grade < 1)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
    std::cout << this->getName() << " was created!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName()), _grade(copy.getGrade())
{
    std::cout << "copy constuctor!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
    }
        return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "bureaucrat " << this->getName() << " went bankrupt" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::increment(int amount)
{
    int grade = this->getGrade();
    if(grade - amount < 1)
        throw Bureaucrat::GradeTooHighException();
    grade -= amount;
    this->_grade = grade;
}

void Bureaucrat::decrement(int amount)
{
    int grade = this->getGrade();
    if(grade + amount > 150)
        throw Bureaucrat::GradeTooLowException();
    grade += amount;
    this->_grade = grade;
}

std::ostream& operator<<(std::ostream& obj, Bureaucrat const &bureaucrat)
{
    obj << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return obj;
}
