/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:50:52 by manwe             #+#    #+#             */
/*   Updated: 2023/10/19 16:23:13 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;
    std::vector<int>::iterator it;
    for (int i = 0; i < 20; i++)
        numbers.push_back(i + 1);
    try
    {
       it = easyfind(numbers, 5);
    }
    catch(const std::exception& e) {}
    std::cout << *it << " found this!" << std::endl;
    try
    {
        it = easyfind(numbers, 69);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    
}