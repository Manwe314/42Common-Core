/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:26:51 by manwe             #+#    #+#             */
/*   Updated: 2023/10/24 23:58:37 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>
#include <ctime>
#include <iterator>
#include <cctype>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<int> _vector;
    std::list<int> _list;
public:
    PmergeMe();
    PmergeMe(int size, char* numbers[]);
    PmergeMe(const PmergeMe &copy);
    PmergeMe& operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortAndPrint();
    void sortVector();
    void sortList();
    
    class DuplicateNumbers : std::exception
    {
        public:
            virtual const char * what() const throw();
    };

    class NegativeNumber : std::exception
    {
        public:
            virtual const char * what() const throw();
    };
    
    class IsAlreadySorted : std::exception
    {
        public:
            virtual const char * what() const throw();
    };
};





#endif
