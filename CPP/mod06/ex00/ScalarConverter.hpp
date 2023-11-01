/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:05:07 by manwe             #+#    #+#             */
/*   Updated: 2023/10/13 18:21:02 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <sstream>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter& operator=(const ScalarConverter& other);
    ScalarConverter(const ScalarConverter& copy);
    ~ScalarConverter();

    static void convert(const std::string& input);
};

#endif
