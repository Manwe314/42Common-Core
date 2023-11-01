/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:58:26 by manwe             #+#    #+#             */
/*   Updated: 2023/10/22 22:28:16 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <algorithm>
#include <cctype>

class BitcoinExchange
{
private:
    std::map<std::string, float> _data_base;
public:
    BitcoinExchange();
    BitcoinExchange(std::string file_name);
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    ~BitcoinExchange();
    
    void printoutput(std::multimap<std::string, float> input);
    void printInputLine(std::string date, float value);
    float dataBaseValue(std::string date);
    
};

class IncorrectFileName : public std::exception
{
    public:
        virtual const char* what() const throw();
};

class IncorrectDate : public std::exception
{
    private:
        std::string _date;
    public:
        IncorrectDate(std::string& date);
        virtual ~IncorrectDate() throw() {}
        virtual const char* what() const throw(); 
};

class IncorrectValue : public std::exception
{
    private:
        std::string _case;
    public:
        IncorrectValue(std::string& casse);
        virtual ~IncorrectValue() throw() {}
        virtual const char* what() const throw();
};

#endif
