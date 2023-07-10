/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkukhale <lkukhale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:22:08 by lkukhale          #+#    #+#             */
/*   Updated: 2023/06/26 17:01:56 by lkukhale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP

# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phonenumber;
		std::string secret;
public:
		void set_first_name(std::string name)
		{
			first_name = name;
		}
		void set_last_name(std::string name)
		{
			last_name = name;
		}
		void set_nickname(std::string name)
		{
			nickname = name;
		}
		void set_phonenumber(std::string name)
		{
			phonenumber = name;
		}
		void set_secret(std::string name)
		{
			secret = name;
		}
		std::string get_first_name()
		{
			return (first_name);
		}
		std::string get_last_name()
		{
			return (last_name);
		}
		std::string get_nickname()
		{
			return (nickname);
		}
		std::string get_phonenumber()
		{
			return (phonenumber);
		}
		std::string get_secret()
		{
			return (secret);
		}
};

#endif
