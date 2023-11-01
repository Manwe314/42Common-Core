/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:52:10 by manwe             #+#    #+#             */
/*   Updated: 2023/10/16 19:02:09 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T a, T b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T max(T a, T b)
{
    if (a > b)
        return (a);
    return (b);
}


#endif
