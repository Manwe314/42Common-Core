/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:25:34 by manwe             #+#    #+#             */
/*   Updated: 2023/10/19 17:49:12 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    Span sp(10000);
    Span smallsp(4);
    std::vector<int> num;

    for (int i = 0; i < 10000; i++)
    {
        num.push_back(std::rand());
    }
    smallsp.addNumber(5);
    sp.addRange(num.begin(), num.end());
    std::cout << "min span: " << sp.shortestSpan() << std::endl;
    std::cout << "max span: " << sp.longestSpan() << std::endl;
    
    try
    {
        std::cout << smallsp.longestSpan();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

try
{
    smallsp.addNumber(30);
    smallsp.addNumber(10);
    smallsp.addNumber(20);
    smallsp.addNumber(40);
}
catch(const std::exception& e)
{
    std::cout << e.what() << std::endl;
}
std::cout << "<------------ smallsp ------------>" <<std::endl;
std::cout << "min span: " << smallsp.shortestSpan() << std::endl;
std::cout << "max span: " << smallsp.longestSpan() << std::endl;
return 0;
}