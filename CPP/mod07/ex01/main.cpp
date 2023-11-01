/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:52:05 by manwe             #+#    #+#             */
/*   Updated: 2023/10/16 21:28:03 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    size_t n = 3;
    int a1[] = {1, 2, 3};
    float a2[] = {3.14f, 2.78f, 1.56f};
    char a3[] = {'a', 'b', 'c'};

    std::cout << "ints: ";
    iter(a1, n, &print);
    std:: cout << std::endl;
    
    std::cout << "floats: ";
    iter(a2, n, &print);
    std:: cout << std::endl;

    std::cout << "chars: ";
    iter(a3, n, &print);
    std:: cout << std::endl;
}