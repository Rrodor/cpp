/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:10 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/13 19:31:58 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	Contact		contact;
	std::string	command;
	int			i;

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
			std::cin >> contact.first_name;
			std::cout << "Enter last name: ";
			std::cin >> contact.last_name;
			std::cout << "Enter nickname: ";
			std::cin >> contact.nickname;
			phonebook.add_contact(contact);
		}
		else if (command == "SEARCH")
		{
			std::cout << "Enter index: ";
			std::cin >> i;
			phonebook.search_contact(i);
		}
	}
	return (0);
}
