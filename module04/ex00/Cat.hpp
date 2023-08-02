/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:29:23 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 14:59:41 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"


class Cat : public Animal
{
	public:
		Cat();
		Cat( Cat const & src );
		~Cat();
		Cat &		operator=( Cat const & rhs );

		void		makeSound() const;
};
