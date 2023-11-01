/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 23:10:21 by manwe             #+#    #+#             */
/*   Updated: 2023/10/24 23:22:12 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cout << "Error: at least 2 arguments are required!" << std::endl;
        return (0);
    }
    
    try
    {
        PmergeMe sorter(argc - 1, argv);
        sorter.sortAndPrint();
    }
    catch(const PmergeMe::DuplicateNumbers & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const PmergeMe::NegativeNumber & e)
    {
        std::cout << e.what() << std::endl;
    }
    catch(const PmergeMe::IsAlreadySorted & e)
    {
        std::cout << e.what() << std::endl;
    }
    
}