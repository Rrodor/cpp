/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:51:35 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/19 19:05:55 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		nb_contact;
	public:
		PhoneBook();
		~PhoneBook();
		void	add_contact(Contact newcontact);
		void	search_contact(int n);
		void	printf_contact();
};

#endif
