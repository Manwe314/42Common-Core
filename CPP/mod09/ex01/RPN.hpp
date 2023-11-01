/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:28:06 by manwe             #+#    #+#             */
/*   Updated: 2023/10/23 20:36:47 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <stack>
#include <exception>

class RPN
{
private:
    std::stack<int> _operands;
public:
    RPN();
    RPN(const RPN &copy);
    RPN& operator=(const RPN &other);
    ~RPN();

    int calculate(std::string input);

    class NotEnoughOperands : std::exception
    {
        public:
            virtual const char * what() const throw();
        
    };
    class DivisonByZero : std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    class InvalidCharacter : std::exception
    {
        public:
            virtual const char * what() const throw();
    };
};


#endif
