/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:00:14 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 18:58:03 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void increment(int amount);
    void decrement(int amount);
    void signForm(AForm& form);
    void executeForm(AForm const &form) const ;

    class GradeTooHighException : std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade Too High, max 1";}
    };
    
    class GradeTooLowException : std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade Too Low, min 150";}
    };
};
std::ostream& operator<<(std::ostream& obj, Bureaucrat const &bureaucrat);



#endif