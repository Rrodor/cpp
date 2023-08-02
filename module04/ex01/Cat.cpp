/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:30:05 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 19:57:14 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( const Cat & src )
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = src;
}

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->_type = rhs.getType();
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->_brain;
}

void		Cat::makeSound() const
{
	std::cout << "Miaou" << std::endl;
}

