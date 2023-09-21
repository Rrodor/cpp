/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:54:39 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 17:07:26 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const & src);
		Serializer & operator=(Serializer const & rhs);
		~Serializer(void);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
};
