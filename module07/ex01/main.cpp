/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 01:09:39 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/08 01:19:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	addone(int *i)
{
	(*i)++;
}

void	print(int *i)
{
	std::cout << *i;
}

void	print(char *i)
{
	std::cout << *i;
}

int	main()
{
	int array[] = {1,2,3,4,5,6,7};
	char str[] = "kiffance";

	::iter(array, 7, print);
	std::cout << std::endl;
	::iter(array, 7, addone);
	std::cout << "addone use" << std::endl;
	::iter(array, 7, print);
	std::cout << std::endl;
	::iter(str, 8, print);
	std::cout << std::endl;
	return (0);
}
