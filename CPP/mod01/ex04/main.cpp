/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 19:15:36 by lkukhale          #+#    #+#             */
/*   Updated: 2023/07/08 19:40:47 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

int main(int argc, char *argv[])
{
	std::ifstream inFile;
	std::ofstream outFile;
	std::string content;
	std::string fileName;
	std::string toReplace;
	std::string toReplaceBy;

	if (argc != 4)
	{
		std::cout << "Invalid number of arguments! <filename> <sting to replace> <string to replace by>" << std::endl;
		return (0);
	}

	fileName = argv[1];
	toReplace = argv[2];
	toReplaceBy = argv[3];

	inFile.open(fileName);
	if (inFile.fail())
	{
		std::cout << "Failed to open the input file" << std::endl;
		return (1);
	}
	std::stringstream buffer;
	buffer << inFile.rdbuf();
	content = buffer.str();
	inFile.close();

	if (toReplace.size() <= 0)
	{
		std::cout << "String to replace is empty" << std::endl;
		return (1);
	}
	std::size_t index = content.find(toReplace);
	while (index != std::string::npos)
	{
		content.erase(index, toReplace.size());
		if (index > content.size())
		{
			index = content.size();
		}
		content.insert(index, toReplaceBy);
		index = content.find(toReplace, index + toReplaceBy.size());
	}

	outFile.open(fileName + ".replace");
	if (outFile.fail())
	{
		std::cout << "Failed to make the output file" << std::endl;
		return (1);
	}
	outFile << content;
	outFile.close();
	return (0);
}
