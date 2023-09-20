/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:47:01 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/14 16:29:55 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v = {2, 3, 9, 5};
	std::list<int> l = {2, 3, 9, 5};
	int n = 3;
	int	i = easyfind<std::vector<int>>(v, n);
	int	j = easyfind<std::list<int>>(l, n);

	if (i >= 0)
		std::cout << "the element index is " << i << " in the vector" << std::endl;
	else
		std::cout << "Error : unable to find the element in the vector" << std::endl;
	if (j >= 0)
		std::cout << "the element index is " << j << " in the list" << std::endl;
	else
		std::cout << "Error : unable to find the element in the list" << std::endl;
	return (0);
}
