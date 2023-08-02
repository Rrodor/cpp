/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:07:01 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 19:41:16 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Brain
{
	private:
		std::string			_ideas[100];
	public:
		Brain();
		Brain( const Brain & src );
		~Brain();
		Brain &				operator=( Brain const & rhs );

		std::string			getIdea(int i) const;
};
