/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:05:43 by manwe             #+#    #+#             */
/*   Updated: 2023/10/11 18:08:40 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid number of arguments, please only use one" << std::endl;
        return 0;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
