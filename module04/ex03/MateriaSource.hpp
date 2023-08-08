/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 23:17:35 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/08 23:46:00 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria*	_formula[4];
		std::string	_formulaName[4];
		int			_forSize;
	public :
		MateriaSource();
		MateriaSource(const MateriaSource & src);
		MateriaSource & operator=(const MateriaSource & src);
		~MateriaSource();

		void learnMateria(AMateria* mat);
		AMateria* createMateria(std::string const & type);
};

#endif
