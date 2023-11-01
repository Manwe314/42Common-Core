/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:38:48 by manwe             #+#    #+#             */
/*   Updated: 2023/10/23 20:53:53 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &copy) : _operands(copy._operands) {}
RPN& RPN::operator=(const RPN &other)
{
    this->_operands = other._operands;
    return *this;
}
RPN::~RPN() {}

const char * RPN::NotEnoughOperands::what() const throw()
{
    return ("Error: Not enough operands left in the stack.");
}

const char * RPN::DivisonByZero::what() const throw()
{
    return ("Error: Division by Zero is undefined.");
}

const char * RPN::InvalidCharacter::what() const throw()
{
    return ("Error: Invalid character used.");
}

int RPN::calculate(std::string input)
{
    int a;
    int b;
    for (size_t i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ' && input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && !::isdigit(input[i]))
            throw RPN::InvalidCharacter();
        if (isdigit(input[i]))
            _operands.push(input[i] - '0');
        if (input[i] == '+')
        {
            if (_operands.size() < 2)
                throw RPN::NotEnoughOperands();
            b = _operands.top();
            _operands.pop();
            a = _operands.top();
            _operands.pop();
            _operands.push(a + b);
        }
        if (input[i] == '-')
        {
            if (_operands.size() < 2)
                throw RPN::NotEnoughOperands();
            b = _operands.top();
            _operands.pop();
            a = _operands.top();
            _operands.pop();
            _operands.push(a - b);
        }
        if (input[i] == '*')
        {
            if (_operands.size() < 2)
                throw RPN::NotEnoughOperands();
            b = _operands.top();
            _operands.pop();
            a = _operands.top();
            _operands.pop();
            _operands.push(a * b);
        }
        if (input[i] == '/')
        {
            if (_operands.size() < 2)
                throw RPN::NotEnoughOperands();
            b = _operands.top();
            _operands.pop();
            a = _operands.top();
            _operands.pop();
            if (b == 0)
                throw RPN::DivisonByZero();
            _operands.push(a / b);
        }
    }
    if (_operands.size() > 1)
        std::cout << "too many operands used the program will display the last extra operand." << std::endl;
    return (_operands.top());
}