/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:26:46 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/09 00:12:24 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _forSize(0)
{
	std::cout << "Material Source created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource & src)
{
	*this = src;
	std::cout << "copy Material Source created" << std::endl;
}

MateriaSource & MateriaSource::operator=(const MateriaSource & src)
{
	*this = src;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia Source destroyed" <<  std::endl;
	for (int i = 0; i < this->_forSize; i++)
	{
		if (this->_formula[i])
			delete this->_formula[i];
	}
}

void MateriaSource::learnMateria(AMateria* mat)
{
	if (this->_forSize < 4)
	{
		this->_formula[this->_forSize] = mat;
		this->_formulaName[this->_forSize] = mat->getType();
		this->_forSize++;
	}
}


AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->_forSize; i++)
		if (this->_formulaName[i] == type)
			return (this->_formula[i]->clone());
	return (NULL);
}
