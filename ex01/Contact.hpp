/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:53:23 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/19 18:44:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		~Contact();
		void		setfirst_name(std::string first_name);
		void		setlast_name(std::string last_name);
		void		setnickname(std::string nickname);
		void		setphone_number(std::string phone_number);
		void		setdarkest_secret(std::string darkest_secret);
		std::string	getfirst_name();
		std::string	getlast_name();
		std::string	getnickname();
		std::string	getphone_number();
		std::string	getdarkest_secret();
};

#endif
