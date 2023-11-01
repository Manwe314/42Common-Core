/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:29:47 by manwe             #+#    #+#             */
/*   Updated: 2023/10/13 17:25:34 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

enum type{
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4,
    SPECIAL_FLOAT = 5,
    SPECIAL_DOUBLE = 6,
    OVERFLOW = 7,
    INVALID_INPUT = 8
};

ScalarConverter::ScalarConverter() {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {(void)other; return *this;}
ScalarConverter::ScalarConverter(const ScalarConverter& copy) {*this = copy;}
ScalarConverter::~ScalarConverter() {}

bool validateInput(const std::string &input)
{
    int point_count = 0;

    if ((int)input.length() == 1 && std::isprint(input[0]))
        return true;
    for (int i = input.length() - 1; i >= 0; i--)
    {
        if (i == (int)input.length() - 1 && input[i] != 'f' && !std::isdigit(input[i]))
            return false;
        if (input[i] == '.')
            point_count++;
        if (i != (int)input.length() - 1 && input[i] != '.' && !std::isdigit(input[i]))
            return false;
    }
    if (point_count > 1)
        return false;
    return true;
}

int detectCase(const std::string& input, std::string (&special_inputs)[6])
{
    int count = 0;
    std::ostringstream size_obj;
    std::string check;
    int i_value;

    for (int i = 0; i < 6; i++)
    {
        if (input == special_inputs[i])
        {
            if (i < 3)
                return SPECIAL_FLOAT;
            else
                return SPECIAL_DOUBLE;
        }
    }
    if (!validateInput(input))
        return INVALID_INPUT;

    if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        return CHAR;

    for (int i = 0; i < (int)input.length(); i++)
        if (input[i] == '.')
            count++;
    if (count == 0 && input[input.length() - 1] != 'f')
    {
        i_value = std::atoi(input.c_str());
        size_obj << i_value;
        check = size_obj.str();
        if (input.compare(check.c_str()) != 0)
            return OVERFLOW;
        return INT;
    }
    if (input[input.length() - 1] == 'f')
        return FLOAT;
    return DOUBLE; 
}

void ScalarConverter::convert(const std::string& input)
{
    std::string special_inputs[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    int casse = detectCase(input, special_inputs);
    int toInt = 0;
    float toFloat = 0.0f;
    double toDouble = 0.0;

    switch (casse)
    {
    case CHAR:
        std::cout << "char: '" << input << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(input[0]) << ".0" <<  std::endl;
        break;
    case INT:
        toInt = std::atoi(input.c_str());
        if (std::isprint(static_cast<char>(toInt)) && toInt < 127)
            std::cout << "char: '" << static_cast<char>(toInt) << "'" << std::endl;
        else
            std::cout << "char: Non Displayable" << std::endl;
        std::cout << "int: " << toInt << std::endl;
        std::cout << "float: " << static_cast<float>(toInt) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(toInt) << ".0" << std::endl; 
        break;
    case FLOAT:
        toFloat = atof(input.c_str());
        if (std::isprint(static_cast<char>(toFloat)))
            std::cout << "char: '" << static_cast<char>(toFloat) << "'" << std::endl;
        else
            std::cout << "char: Non Displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(toFloat) << std::endl;
        std::cout << "float: " << toFloat << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(toFloat) << std::endl; 
        break;
    case DOUBLE:
        toDouble = static_cast<double>(std::atof(input.c_str()));
        if (std::isprint(static_cast<char>(toDouble)))
            std::cout << "char: '" << static_cast<char>(toDouble) << "'" << std::endl;
        else
            std::cout << "char: Non Displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(toDouble) << std::endl;
        std::cout << "float: " << static_cast<float>(toDouble) << "f" << std::endl;
        std::cout << "double: " << toDouble << std::endl;
        break;
    case SPECIAL_FLOAT:
        for (int i = 0; i < 3; i++)
            if (input == special_inputs[i])
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << special_inputs[i] << std::endl;
                std::cout << "double: " << special_inputs[i + 3] <<std::endl;
                break;
            }
        break;
    case SPECIAL_DOUBLE:
        for (int i = 3; i < 6; i++)
            if (input == special_inputs[i])
            {
                std::cout << "char: impossible" << std::endl;
                std::cout << "int: impossible" << std::endl;
                std::cout << "float: " << special_inputs[i - 3] << std::endl;
                std::cout << "double: " << special_inputs[i] <<std::endl;
                break;
            }
        break;
    case OVERFLOW:
        std::cout << "the input overflows it does not make sense to convert" << std::endl;
        break;
    default:
        std::cout << "Invalid input please use a single char, an int, a float, a double or a special infinty input" << std::endl;  
        break;
    }
}