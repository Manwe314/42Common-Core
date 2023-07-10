/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:23:36 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/26 17:04:58 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP

#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
			Contact contacts[8];
			int index;

	public:
		PhoneBook()
		{
			index = 0;
			std::cout << "7 Greatings Traveler, this here be a PHNEBOOK! use it as ye may please!" << std::endl;
		}
		~PhoneBook()
		{
			std::cout << "ye be warrned ye PhoneBook is lost forever, fear not ye may make a new one!" << std::endl;
		}
		int has_entry(int id)
		{
			if (id > 7)
				return (0);
			if (contacts[id].get_first_name().size() <= 0)
				return (0);
			return (1);
		}
		void add(Contact new_contact, int new_index)
		{
			if (new_index > 7)
			{
				std::cout << "No space left in the phonebook will overwrite the oldest contact" << std::endl;
				new_index = new_index % 8;
			}
			contacts[new_index].set_first_name(new_contact.get_first_name());
			contacts[new_index].set_last_name(new_contact.get_last_name());
			contacts[new_index].set_nickname(new_contact.get_nickname());
			contacts[new_index].set_phonenumber(new_contact.get_phonenumber());
			contacts[new_index].set_secret(new_contact.get_secret());
			index = new_index;
		}
		void display_phonebook()
		{
			std::string temp;

			std::cout << "____________________________________________" << std::endl;
			std::cout << "|  index   |first name|last name |nickname  |" << std::endl;
			std::cout << "|----------|----------|----------|----------|" << std::endl;
			for (int i = 0; i < 8; i++)
			{
				if (contacts[i].get_first_name().size() > 0)
				{
					std::cout << "|         " << i << "|";
					temp = contacts[i].get_first_name();
					if (temp.size() > 10)
					{
						temp.resize(10);
						temp[9] = '.';
					}
					std::cout << std::setw(10) << temp << "|";
					temp = contacts[i].get_last_name();
					if (temp.size() > 10)
					{
						temp.resize(10);
						temp[9] = '.';
					}
					std::cout << std::setw(10) << temp << "|";
					temp = contacts[i].get_nickname();
					if (temp.size() > 10)
					{
						temp.resize(10);
						temp[9] = '.';
					}
					std::cout << std::setw(10) << temp << "|";
					std::cout << std::endl;
				}
			}
			std::cout << "|----------|----------|----------|----------|" << std::endl;
		}
		void search(int id)
		{
			if (this->has_entry(id) == 0)
			{
				std::cout << "The index " << id << " is not in this PhoneBook please use SEARCH again (make sure that an entry for this id exists)." << std::endl;
			}
			else
			{
				std::cout <<"First name: " << contacts[id].get_first_name()  << std::endl;
				std::cout <<"Last name: "  << contacts[id].get_last_name() << std::endl;
				std::cout <<"Nickname: "  << contacts[id].get_nickname() << std::endl;
				std::cout <<"Phone Number: "  << contacts[id].get_phonenumber() << std::endl;
				std::cout <<"Secret: "  << contacts[id].get_secret() << std::endl;
			}
		}
};



#endif
