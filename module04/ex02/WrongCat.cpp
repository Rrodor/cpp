/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 18:17:36 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 18:18:00 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal::WrongAnimal()
{
	std::cout << "WrongCat Constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat & src )
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "miaou" << std::endl;
}
