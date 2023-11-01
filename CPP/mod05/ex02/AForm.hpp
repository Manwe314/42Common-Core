/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:51:59 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 19:09:08 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm
{
private:
    const std::string _name;
    const int _grade_sign_min;
    const int _grade_exec_min;
    bool _is_signed;
    
public:
    AForm();
    AForm(std::string name, int grade_sign_min, int grade_exec_min);
    AForm(const AForm &copy);
    AForm& operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    int getGradeSignMin() const;
    int getGradeExecMin() const;
    bool getIsSigned() const;

    void beSigned(Bureaucrat& buro);

    virtual void execute(Bureaucrat const & executor) const = 0;
    
    class GradeTooHighException : std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade Too High for this form";}
    };
    
    class GradeTooLowException : std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade Too Low to sign this form";}
    };

    class NotSignedException : std::exception
    {
        public:
            virtual const char* what() const throw() { return "The From is not signed";}
    };

};
std::ostream& operator<<(std::ostream& obj, AForm const &form);


#endif