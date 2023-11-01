/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:56:45 by manwe             #+#    #+#             */
/*   Updated: 2023/10/10 19:21:00 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "Shrubs shreded" << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const 
{
    if (this->getIsSigned() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeExecMin())
        throw AForm::GradeTooLowException();
    std::cout << "huehehe" << std::endl;
    std::string filename = this->_target + "_shrubery";
    std::ofstream file(filename.c_str());
    if (file.is_open()) 
    {
        file << "                     / / /" << std::endl;
        file << "                   /        /  /     //    /" << std::endl;
        file << "                /                 /         /  /" << std::endl;
        file << "                                /" << std::endl;
        file << "                               /                //" << std::endl;
        file << "               /          /            /              /" << std::endl;
        file << "               /            '/,        /               /" << std::endl;
        file << "               /              'b      *" << std::endl;
        file << "                /              '$    //                //" << std::endl;
        file << "               /    /           $:   /:               /" << std::endl;
        file << "             //      /  //      */  @):        /   / /" << std::endl;
        file << "                          /     :@,@):   ,/**:'   /" << std::endl;
        file << "              /      /,         :@@*: //**'      /   /" << std::endl;
        file << "                       '/o/    /:(@'/@*\"'  /" << std::endl;
        file << "               /  /       'bq,//:,@@*'   ,*      /  /" << std::endl;
        file << "                          ,p$q8,:@)'  /p*'      /   /" << std::endl;
        file << "                   /     '  / '@@Pp@@*'    /  /" << std::endl;
        file << "                    /  / //    Y7'.'     /  /" << std::endl;
        file << "                              :@):." << std::endl;
        file << "                             .:@:'." << std::endl;
        file << "                           .::(@:.      " << std::endl;
        file << std::endl;
        file.close();
    }
    else
    {
        std::cout << "error while opeing the shrubery file" << std::endl;
    }
}
