/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 21:50:49 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 14:04:25 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int		main(void)
{
	Data	*ptr = new Data;
	Data	*ptr2;
	uintptr_t	raw;

	ptr->s = "test string";
	ptr->n = 42;
	ptr->d = 42.42;
	ptr->f = 24.24f;
	std::cout << "ptr->s = " << ptr->s << std::endl;
	std::cout << "ptr->n = " << ptr->n << std::endl;
	std::cout << "ptr->d = " << ptr->d << std::endl;
	std::cout << "ptr->f = " << ptr->f << std::endl;
	std::cout << "ptr = " << ptr << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "raw (uintptr_t) = Serializer::serialize(ptr) = " << raw << std::endl;
	ptr2 = Serializer::deserialize(raw);
	std::cout << "ptr2 (Data *) = Serializer::deserialize(raw) = " << ptr2 << std::endl;
	std::cout << "ptr2->s = " << ptr2->s << std::endl;
	std::cout << "ptr2->n = " << ptr2->n << std::endl;
	std::cout << "ptr2->d = " << ptr2->d << std::endl;
	std::cout << "ptr2->f = " << ptr2->f << std::endl;
	delete ptr;
	return (0);
}
