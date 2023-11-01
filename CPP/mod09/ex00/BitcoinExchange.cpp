/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:52:08 by manwe             #+#    #+#             */
/*   Updated: 2023/10/22 22:28:38 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return true;
    else
        return false;
}

bool isValidDate(std::string date)
{
    if (date.size() < 8)
        std::cout << date << std::endl;
    int year = std::atoi(date.c_str());
    int month = std::atoi((date.substr(5)).c_str());
    int day = std::atoi((date.substr(8)).c_str());
    
    if (year < 2009)
        return false;
    if (month > 12 || day > 31 || month == 0 || day == 0)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    if (month == 2 && day > 29)
        return false;
    if (month == 2 && !isLeapYear(year) && day > 28)
        return false;
    return true;
}

bool isValidLine(std::string line)
{
    int point_count = 0;
    int dash_count = 0;
    int comma_count = 0;
    
    if (line.size() < 12)
        return false;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (!std::isdigit(line[i]) && line[i] != '-' && line[i] != ',' && line[i] != '.')
            return false;
        if (line[i] == '-')
            dash_count++;
        else if (line[i] == ',')
            comma_count++;
        else if (line[i] == '.')
            point_count++;
    }
    if (dash_count != 2 || comma_count != 1 || point_count > 1)
        return false;
    return true;
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string file_name)
{
    std::ifstream database;
    std::string line;
    std::string value;
    std::string date;
    
    database.open(file_name.c_str());
    if (!database.is_open())
        throw IncorrectFileName();
    while (std::getline(database, line))
    {
        if (isValidLine(line))
        {
            value = line.substr(line.find(',') + 1);
            date = line.substr(0, 10);
            _data_base.insert(std::make_pair(date, std::atof(value.c_str())));
        }
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _data_base(copy._data_base) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
    _data_base = other._data_base;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

const char* IncorrectFileName::what() const throw()
{
    return ("Error: could not open file.");
}

IncorrectDate::IncorrectDate(std::string& date)
{
    this->_date = "Error: bad input => " + date;
}

const char* IncorrectDate::what() const throw()
{
    return (_date.c_str());
}

IncorrectValue::IncorrectValue(std::string& casse)
{
    this->_case = "Error: " + casse;
}

const char* IncorrectValue::what() const throw()
{
    return (_case.c_str());
}

float BitcoinExchange::dataBaseValue(std::string date)
{
    std::map<std::string, float>::iterator it = this->_data_base.find(date);
    if (it != this->_data_base.end())
        return it->second; 
    it--;
    while (it != this->_data_base.begin())
    {
        if (date > it->first)
            return it->second;
        it--;
    }
    return it->second;
}

void BitcoinExchange::printInputLine(std::string date, float value)
{
    std::string low_num = "not a positive number.";
    std::string high_num = "too large a number.";

    if (value < 0.0f)
        throw IncorrectValue(low_num);
    if (value > 1000.0f)
        throw IncorrectValue(high_num);
    if (!isValidDate(date))
        throw IncorrectDate(date);
    std::cout << date << " => " << value << " = ";
}
    
void BitcoinExchange::printoutput(std::multimap<std::string, float> input)
{
    std::multimap<std::string, float>::iterator it;
    for ( it = input.begin(); it != input.end(); it++)
    {
        try
        {
            printInputLine(it->first, it->second);
            std::cout << it->second * dataBaseValue(it->first) << std::endl;
        }
        catch(const IncorrectDate& e)
        {
            std::cout << e.what() << std::endl;
        }
        catch(const IncorrectValue& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}