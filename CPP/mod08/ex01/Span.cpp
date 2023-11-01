/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:52:41 by manwe             #+#    #+#             */
/*   Updated: 2023/10/19 17:50:30 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0) {}
Span::Span(unsigned int N) : _size(N) {}
Span::Span(const Span &copy) : _size(copy._size), _numbers(copy._numbers) {*this = copy;}
Span& Span::operator=(const Span &other)
{
    if (this == &other)
        return *this;
    this->_size = other._size;
    this->_numbers = other._numbers;
    return *this;
}
Span::~Span() {}




void Span::addNumber(int number)
{
    if (this->_numbers.size() == this->_size)
        throw Span::SpanIsFullException();
    this->_numbers.push_back(number);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (this->_numbers.size() + std::distance(begin, end) > this->_size)
        throw Span::SpanIsFullException();
    this->_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
    if (this->_numbers.size() < 2 || this->_size < 2)
        throw Span::SpanIsTooSmallException();
    std::sort(this->_numbers.begin(), this->_numbers.end());
    std::vector<int>::iterator it = this->_numbers.begin();
    int min = *(it + 1) - *it;
    while (it != this->_numbers.end())
    {
        if(it != (this->_numbers.end() - 1) && *(it + 1) - *it < min)
        {
            min = *(it + 1) - *it;
        }
        it++;
    }
    return min;
}

int Span::longestSpan()
{
    if (this->_numbers.size() < 2 || this->_size < 2)
        throw Span::SpanIsTooSmallException();
    int span = *std::max_element(this->_numbers.begin(), this->_numbers.end()) - *std::min_element(this->_numbers.begin(), this->_numbers.end());
    return span;
}