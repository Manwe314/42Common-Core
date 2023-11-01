/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:28:15 by manwe             #+#    #+#             */
/*   Updated: 2023/10/19 19:46:25 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <deque>
#include <stack>
#include <list>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > 
{
public:
    MutantStack() {};
    MutantStack(MutantStack const &copy) : std::stack<T>(copy) {};
    ~MutantStack() { this->c.clear();};
    MutantStack& operator=(const MutantStack &other)
    {
        if(other != *this)
            this->c = other.c;
        return *this;
    }

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {return this->c.begin();}
    iterator end() {return this->c.end();}
};




#endif
