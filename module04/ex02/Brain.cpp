/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:08:07 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 19:56:55 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &				Brain::operator=( Brain const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs.getIdea(i);
	}
	return *this;
}

std::string		Brain::getIdea(int i) const
{
	return (this->_ideas[i]);
}
