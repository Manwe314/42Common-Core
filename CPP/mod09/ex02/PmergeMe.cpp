/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 19:10:31 by manwe             #+#    #+#             */
/*   Updated: 2023/10/25 00:41:44 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int size, char* numbers[]) 
{
    int number;
    int id;
    
    for (int i = 1; i <= size ; i++)
    {
        number = atoi(numbers[i]);
        if (number < 0)
            throw PmergeMe::NegativeNumber();
        for (int j = 0; j < (int)_vector.size(); j++)
        {
            if (number == _vector[j])
                throw PmergeMe::DuplicateNumbers();
        }
        _vector.push_back(number);
        _list.push_back(number);
    }
    id = 1;
    while (id != (int)_vector.size())
    {
        if (_vector[id - 1] > _vector[id])
            break;
        id++; 
    }
    if (id == (int)_vector.size())
        throw PmergeMe::IsAlreadySorted();
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _list(copy._list) {}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) 
{
    this->_vector = other._vector;
    this->_list = other._list;
    return *this;   
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::DuplicateNumbers::what() const throw()
{
    return ("Error: Duplicate numbers used");
}

const char* PmergeMe::NegativeNumber::what() const throw()
{
    return ("Error: Negative number used");
}

const char* PmergeMe::IsAlreadySorted::what() const throw()
{
    return ("Error: The input is already sorted");
}

std::list<int> merge(std::list<int> one, std::list<int> two) 
{
    std::list<int> merged;
    
    while (!one.empty() && !two.empty()) 
    {
        if (one.front() < two.front()) 
        {
            merged.push_back(one.front());
            one.pop_front();
        } 
        else 
        {
            merged.push_back(two.front());
            two.pop_front();
        }
    }

    while (!one.empty()) 
    {
        merged.push_back(one.front());
        one.pop_front();
    }

    while (!two.empty()) 
    {
        merged.push_back(two.front());
        two.pop_front();
    }
    return merged;
}

std::list<int> insertion_sort_list(std::list<int> lst) 
{
    std::list<int>::iterator it, jt, prev;
    int temp;
    
    for (it = lst.begin(); it != lst.end(); ++it) 
    {
        jt = it;
        prev = it;
        while (jt != lst.begin() && *(--prev) > *jt) 
        {
            temp = *prev;
            *prev = *jt;
            *jt = temp;
            jt--;
        }
    }
    return lst;
}

std::list<int> merge_insert_sort_list(std::list<int> initial)
{
    if (initial.size() < 10)
        return insertion_sort_list(initial);

    std::list<int> sub_one;
    std::list<int> sub_two;

    for (int i = 0; i < (int)initial.size() / 2; i++)
    {
        sub_one.push_back(initial.front());
        initial.pop_front();
    }

    while (!initial.empty())
    {
        sub_two.push_back(initial.front());
        initial.pop_front();
    }

    sub_one = merge_insert_sort_list(sub_one);
    sub_two = merge_insert_sort_list(sub_two);

    return merge(sub_one, sub_two);
}


std::vector<int> merge(std::vector<int> one, std::vector<int> two)
{
    std::vector<int> merged;

    while (one.size() != 0 && two.size() != 0)
    {
        if (one[0] < two[0])
        {
            merged.push_back(one[0]);
            one.erase(one.begin());
        }
        else
        {
            merged.push_back(two[0]);
            two.erase(two.begin());
        }
    }
    while (one.size() != 0)
    {
        merged.push_back(one[0]);
        one.erase(one.begin());
    }
    while (two.size() != 0)
    {
        merged.push_back(two[0]);
        two.erase(two.begin());
    }
    return (merged);
}

std::vector<int> insertion_sort_vector(std::vector<int> vect)
{
    int temp;
    int j;
    for (int i = 1; i < (int)vect.size(); i++)
    {
        j = i;
        while (j > 0 && vect[j - 1] > vect[j])
        {
            temp = vect[j - 1];
            vect[j - 1] = vect[j];
            vect[j] = temp;
            j--;
        }
    }
    return (vect);
}

std::vector<int> merge_insert_sort_vector(std::vector<int> initial)
{
    if (initial.size() < 10)
        return insertion_sort_vector(initial);
    
    std::vector<int> sub_one;
    std::vector<int> sub_two;
    sub_one.assign(initial.begin(), initial.begin() + (initial.size() / 2));
    sub_two.assign(initial.begin() + (initial.size() /2), initial.end());
    
    sub_one = merge_insert_sort_vector(sub_one);
    sub_two = merge_insert_sort_vector(sub_two);
    
    return (merge(sub_one, sub_two));
}

void PmergeMe::sortList()
{
    _list = merge_insert_sort_list(_list);
    
}

void PmergeMe::sortVector()
{
    _vector = merge_insert_sort_vector(_vector);
}

void PmergeMe::sortAndPrint()
{
    clock_t vector_start_time;
    clock_t vector_end_time;
    clock_t list_start_time;
    clock_t list_end_time;
    double elapsed_time_vector;
    double elapsed_time_list;



    std::cout << "Before: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    
    vector_start_time = clock();
    sortVector();
    vector_end_time = clock();
    elapsed_time_vector = static_cast<double>(vector_end_time - vector_start_time) / CLOCKS_PER_SEC * 1000;
    
    list_start_time = clock();
    sortList();
    list_end_time = clock();
    elapsed_time_list = static_cast<double>(list_end_time - list_start_time) / CLOCKS_PER_SEC * 1000;
    
    std::cout << "After: ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;

    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector<int> : " << elapsed_time_vector << " us" << std::endl;
    std::cout << "Time to process a range of " << _list.size() << " elements with std::list<int> : " << elapsed_time_list << " us" << std::endl;
}


