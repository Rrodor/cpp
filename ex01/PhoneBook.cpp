/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 18:25:33 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/13 19:14:40 by rrodor           ###   ########.fr       */
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
		std::cout << "PhoneBook is full" << std::endl;
	}
}

void	PhoneBook::search_contact(int n)
{
	if (n < PhoneBook::nb_contact)
	{
		std::cout << "First name: " << PhoneBook::contacts[n].first_name << std::endl;
		std::cout << "Last name: " << PhoneBook::contacts[n].last_name << std::endl;
		std::cout << "Nickname: " << PhoneBook::contacts[n].nickname << std::endl;
	}
	else
	{
		std::cout << "Contact not found" << std::endl;
	}
}
