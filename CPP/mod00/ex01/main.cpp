/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:21:23 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/20 22:55:26 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void handle_search(PhoneBook& phonebook)
{
	int id;
	std::string str;

	phonebook.display_phonebook();
	while (std::cin.eof() == false)
	{
		std::cout << "please enter the index of the Contact you want to see > ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '0' && str[0] <= '9')
				break;
			else
				std::cout << "youll need to input 1 numeric character please" << std::endl;
		}
	}
	if (std::cin.eof() == true)
		return ;
	if (str == "")
	{
		std::cout << "we need a numeric value between 0 and 7, please be kind and use SEARCH again... no mistakes this time..." << std::endl;
		return ;
	}
	id = (int)(str[0] - '0');
	if (id <= 7 && id >= 0)
		phonebook.search(id);
	else
		std::cout << "Tis but a humble phonebook it only holds 8 Contacts (0-7 indexes) please use one in range" << std::endl;
}

void handle_add(PhoneBook& phonebook, int index)
{
	Contact new_contact;
	std::string str;

	std::cout << "Enter first name: ";
	while(!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str), str != "")
			new_contact.set_first_name(str);
		break;
	}
	str = "";
	std::cout << "Enter last name: ";
	while(!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str), str != "")
			new_contact.set_last_name(str);
		break;
	}
	str = "";
	std::cout << "Enter nickname: ";
	while(!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str), str != "")
			new_contact.set_nickname(str);
		break;
	}
	str = "";
	std::cout << "Enter phone number: ";
	while(!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str), str != "")
			new_contact.set_phonenumber(str);
		break;
	}
	str = "";
	std::cout << "Enter secret: ";
	while(!std::cin.eof() && str == "")
	{
		if (std::getline(std::cin, str), str != "")
			new_contact.set_secret(str);
		break;
	}
	if (new_contact.get_first_name().size() == 0 || new_contact.get_last_name().size() == 0 || new_contact.get_nickname().size() == 0 || new_contact.get_phonenumber().size() == 0 || new_contact.get_secret().size() == 0)
	{
		std::cout << "oops sorry a Contact detail can not be empty this contact will not be added. try using ADD again" << std::endl;
		return ;
	}
	else
		phonebook.add(new_contact, index);
}

int main()
{
	PhoneBook phonebook = PhoneBook();
	int index;
	std::string input;

	index = 0;
	while (input != "EXIT")
	{
		std::cout << "Your Command > ";
		std::getline(std::cin, input);
		if (input == "ADD")
		{
			handle_add(phonebook, index);
			index++;
		}
		else if (input == "SEARCH")
			handle_search(phonebook);
		else if (input != "EXIT" && std::cin.eof() == false)
		{
			std::cout << "The commands are ADD SEARCH & EXIT!" << std::endl;
		}
		if (std::cin.eof() == true)
		{
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
