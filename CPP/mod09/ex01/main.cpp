/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:48:41 by manwe             #+#    #+#             */
/*   Updated: 2023/10/23 20:52:41 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        std::cout << "Plase input only one argument using the quotes" << std::endl;
        return (0);
    }
    RPN calculator;
    try
    {
        std::cout << calculator.calculate(argv[1]) << std::endl;
    }
    catch(const RPN::DivisonByZero& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const RPN::InvalidCharacter& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const RPN::NotEnoughOperands& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);   
}