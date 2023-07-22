/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:32:06 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/21 12:33:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	return ;
}

Weapon::Weapon(std::string type)
{
	this->type = type;
	return ;
}

Weapon::~Weapon(void)
{
	return ;
}

std::string const &Weapon::getType(void)
{
	return (this->type);
}

void	Weapon::setType(std::string newtype)
{
	this->type = newtype;
}
