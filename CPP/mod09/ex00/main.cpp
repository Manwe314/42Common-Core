/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manwe <manwe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:58:21 by manwe             #+#    #+#             */
/*   Updated: 2023/10/22 22:43:30 by manwe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool isCorrectInput(std::string line)
{
    int pipe_count = 0;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (!std::isdigit(line[i]) && line[i] != '-' && line[i] != '|' && line[i] != '.' && line[i] != ' ')
            return false;
        if(line[i] == '|')
            pipe_count++;
    }
    if (pipe_count >= 2)
        return false;
    return true;
}

std::multimap<std::string, float> prepareInput(char *file_name)
{
    std::multimap<std::string, float> input;
    std::ifstream inp_file(file_name);
    std::string line;
    std::string value;
    std::string date;
    int line_number = 0;
    
    if(!inp_file)
        throw IncorrectFileName();
    while (std::getline(inp_file, line))
    {
        if (isCorrectInput(line))
        {
            if (line.find('|') != std::string::npos)
            {
                date = line.substr(0, line.find('|'));
                value = line.substr(line.find('|') + 1);
            }
            else
            {
                date = line;
                value = "0.0";
            }
            date.erase(std::remove_if(date.begin(), date.end(), ::isspace), date.end());
            input.insert(std::make_pair(date, std::atof(value.c_str())));
        }
        else
        {
            if (line_number != 0)
                std::cout << "Formating error on line: " << line_number << " => " << line << std::endl;
        }
        line_number++;
    }
    return input;
}

int main(int argc, char *argv[])
{
    std::multimap<std::string, float> input;
    std::string database_name = "data.csv";

    if (argc == 1)
    {
        std::cout << "Error: could not open file." << std::endl;
        return (0);
    }
    
    try
    {
        input = prepareInput(argv[1]);
        BitcoinExchange btc(database_name);
        btc.printoutput(input);
    }
    catch(const IncorrectFileName& e)
    {
        std::cout << e.what() << std::endl;
    }
    


}