/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:41:06 by manwe             #+#    #+#             */
/*   Updated: 2023/10/16 21:27:54 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, size_t array_size, void (*f)(T &))
{
    for (size_t i = 0; i < array_size; i++)
        f(array[i]);
}

template<typename T>
void print(T &obj)
{
    std::cout << obj << " ";
}
#endif
