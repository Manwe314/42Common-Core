/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:28:48 by manwe             #+#    #+#             */
/*   Updated: 2023/10/17 18:44:43 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    Array<int> numbers(10);
    Array<char> initials(10);
    
    for (unsigned int i = 0; i < 10; i++)
    {
        numbers[i] = i + 1;
        initials[i] = 'A' + i;
    }

    Array<char> ini(initials);
    Array<int> num;
    num = numbers;

    for (unsigned int i = 0; i < 10; i++)
        std::cout << num[i] << " " << ini[i] << std::endl;

    try
    {
        std::cout << num[30] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return (0);
}