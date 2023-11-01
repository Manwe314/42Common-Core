/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:43:26 by manwe             #+#    #+#             */
/*   Updated: 2023/10/06 19:55:45 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat joe;
    Bureaucrat sony("sony", 42);
    Bureaucrat abby;

    abby = sony;

    joe.increment(30);
    abby.decrement(30);

    try
    {
        sony.increment(50);
    }
    catch (Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Oops: " << e.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Oops: " << e.what() << std::endl;
    }

    std::cout << "best bureaucrat: " << abby << std::endl;
    std::cout << "best bureaucrat: " << joe << std::endl;
    std::cout << "best bureaucrat: " << sony << std::endl;

}