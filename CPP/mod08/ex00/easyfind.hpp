/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:42:05 by manwe             #+#    #+#             */
/*   Updated: 2023/10/19 16:24:06 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T& container, int to_find)
{
    typename T::iterator target = std::find(container.begin(), container.end(), to_find);
    if (target == container.end())
        throw std::runtime_error("Provided container does not contain the desired int");
    return (target);
}


#endif
