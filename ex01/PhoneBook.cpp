/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:25:33 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/19 19:27:24 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::add_contact(Contact newcontact)
{
	if (PhoneBook::nb_contact < 8)
	{
		PhoneBook::contacts[PhoneBook::nb_contact] = newcontact;
		PhoneBook::nb_contact++;
	}
	else
	{
		PhoneBook::nb_contact = 0;
		PhoneBook::contacts[PhoneBook::nb_contact] = newcontact;
		PhoneBook::nb_contact++;
	}
}

void	PhoneBook::search_contact(int n)
{
	std::string	str;

	if (n < PhoneBook::nb_contact)
	{
		std::cout << "First name: " << PhoneBook::contacts[n].getfirst_name() << std::endl;
		std::cout << "Last name: " << PhoneBook::contacts[n].getlast_name() << std::endl;
		std::cout << "Nickname: " << PhoneBook::contacts[n].getnickname() << std::endl;
		std::cout << "Phone number: " << PhoneBook::contacts[n].getphone_number() << std::endl;
		std::cout << "Darkest secret: " << PhoneBook::contacts[n].getdarkest_secret() << std::endl;
	}
	else
	{
		std::cout << "Contact not found" << std::endl;
	}
}

void	PhoneBook::printf_contact()
{
	int			i;
	std::string	str;

	i = 0;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < PhoneBook::nb_contact && i < 8)
	{
		std::cout << std::setw(10) << i << "|";
		str = PhoneBook::contacts[i].getfirst_name();
		if (str.length() > 10)
			std::cout << str.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << str << "|";
		str = PhoneBook::contacts[i].getlast_name();
		if (str.length() > 10)
			std::cout << str.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << str << "|";
		str = PhoneBook::contacts[i].getnickname();
		if (str.length() > 10)
			std::cout << str.substr(0, 9) << ".|";
		else
			std::cout << std::setw(10) << str << "|";
		std::cout << std::endl;
		i++;
	}
}

PhoneBook::PhoneBook()
{
	PhoneBook::nb_contact = 0;
	return ;
}

PhoneBook::~PhoneBook()
{
	return ;
}
