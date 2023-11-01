/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:04:01 by manwe             #+#    #+#             */
/*   Updated: 2023/10/17 18:43:09 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
private:
    T* _array;
    unsigned int _size;

public:
    Array()
    {
        _size = 0;
        _array = new T[0];
    }
    Array(unsigned int size)
    {
        _size = size;
        _array = new T[size];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = 0;
    }
    Array(const Array &copy)
    {
        _size = copy.size();
        _array = new T[copy.size()];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = copy[i];
    }
    Array<T>& operator=(const Array &other)
    {
        delete[] _array;
        _size = other.size();
        _array = new T[other.size()];
        for (unsigned int i = 0; i < _size; i++)
            _array[i] = other[i];
        return *this;
    }
    T& operator[](unsigned int index)
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return (_array[index]);
    }
    const T& operator[](unsigned int index) const
    {
        if (index >= _size)
            throw std::out_of_range("Index out of bounds");
        return (_array[index]);
    }
    unsigned int size() const
    {
        return (_size);
    }
    ~Array()
    {
        delete[] _array;
    }
};


#endif
