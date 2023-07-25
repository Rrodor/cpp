/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:10 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/19 19:23:27 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	command;
	std::string	str;
	char		i;

	i = 0;
	while (1)
	{
		std::cout << "Enter a command: ";
		std::cin >> command;
		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			std::cout << "Enter first name: ";
			std::cin >> str;
			contact.setfirst_name(str);
			std::cout << "Enter last name: ";
			std::cin >> str;
			contact.setlast_name(str);
			std::cout << "Enter nickname: ";
			std::cin >> str;
			contact.setnickname(str);
			std::cout << "Enter phone number: ";
			std::cin >> str;
			contact.setphone_number(str);
			std::cout << "Enter darkest secret: ";
			std::cin >> str;
			contact.setdarkest_secret(str);
			phonebook.add_contact(contact);
		}
		else if (command == "SEARCH")
		{
			phonebook.printf_contact();
			std::cout << "Enter index: ";
			std::cin >> i;
			if (!isdigit(i))
				std::cout << "Index must be a number" << std::endl;
			else if (i < 48 || i > 55)
				std::cout << "Index must be between 0 and 7" << std::endl;
			else
				phonebook.search_contact(i - 48);
		}
	}
	return (0);
}
