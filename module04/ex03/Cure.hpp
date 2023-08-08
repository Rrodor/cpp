/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:15:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/08 22:53:12 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure & src);
		Cure & operator=(const Cure & ref);
		~Cure();

		AMateria *clone() const;
		void use(ICharacter& target);
};

#endif
