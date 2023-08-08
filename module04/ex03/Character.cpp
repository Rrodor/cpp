/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:38:42 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/09 00:10:35 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("nobody")
{
	std::cout << "character created" << std::endl;
}

Character::Character(std::string name) : _name(name), _invSize(0)
{
	std::cout << name << " character created" << std::endl;
}

Character::Character(const Character & src)
{
	*this = src;
	std::cout << "copy character created" << std::endl;
}

Character & Character::operator=(const Character & src)
{
	std::cout << "copy " << src.getName() << " into " << this->_name << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (int i = 0; i < src.getInvSize(); i++)
		this->_inventory[i] = src.getMateria(i);
	this->_invSize = src.getInvSize();
	return (*this);
}

Character::~Character()
{

	std::cout << this->_name << " Character destroyed" << std::endl;
	if (this->_invSize)
	{
		for (int i = 0; i < this->_invSize; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
		}
	}
}

std::string const & Character::getName() const
{
	return (this->_name);
}

int	Character::getInvSize() const
{
	return (this->_invSize);
}

AMateria * Character::getMateria(int id) const
{
	return (this->_inventory[id]);
}

void	Character::equip(AMateria * m)
{
	if (this->_invSize < 4)
	{
		this->_inventory[this->_invSize] = m;
		this->_invSize++;
		std::cout << this->getName() << " picked up " << m->getType() << std::endl;
	}
	else
		std::cout << this->getName() << " cannot picked up " << m->getType() << " because is inventory is full" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= this->_invSize || !this->_inventory[idx])
		std::cout << "cannot unequip Materia number " << idx << std::endl;
	else
	{
		std::cout << this->_name << " drop " << this->_inventory[idx]->getType() << std::endl;
		this->_inventory[idx] = NULL;
	}
}


void	Character::use(int idx, ICharacter& target)
{
	if (idx >= this->_invSize || !this->_inventory[idx])
		std::cout << "cannot use Materia number : " << idx << std::endl;
	else
		this->_inventory[idx]->use(target);
}

