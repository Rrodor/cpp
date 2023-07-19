/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:22:11 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/19 18:49:34 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	return ;
}

Contact::~Contact()
{
	return ;
}

void	Contact::setfirst_name(std::string first_name)
{
	Contact::first_name = first_name;
}

void	Contact::setlast_name(std::string last_name)
{
	Contact::last_name = last_name;
}

void	Contact::setnickname(std::string nickname)
{
	Contact::nickname = nickname;
}

void	Contact::setphone_number(std::string phone_number)
{
	Contact::phone_number = phone_number;
}

void	Contact::setdarkest_secret(std::string darkest_secret)
{
	Contact::darkest_secret = darkest_secret;
}

std::string	Contact::getfirst_name()
{
	return (Contact::first_name);
}

std::string	Contact::getlast_name()
{
	return (Contact::last_name);
}

std::string	Contact::getnickname()
{
	return (Contact::nickname);
}

std::string	Contact::getphone_number()
{
	return (Contact::phone_number);
}

std::string	Contact::getdarkest_secret()
{
	return (Contact::darkest_secret);
}

