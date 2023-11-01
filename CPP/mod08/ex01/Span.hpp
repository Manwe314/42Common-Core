/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:28:26 by manwe             #+#    #+#             */
/*   Updated: 2023/10/19 17:05:14 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
private:
    unsigned int _size;
    std::vector<int> _numbers;
public:
    Span();
    Span(unsigned int N);
    Span(const Span &copy);
    Span& operator=(const Span &other);
    ~Span();

    void addNumber(int number);
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    
    int shortestSpan();
    int longestSpan();

    class SpanIsFullException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return ("Span is Full");};
    };
    class SpanIsTooSmallException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return ("Span is to small to define a span");};
    };
    
};



#endif
