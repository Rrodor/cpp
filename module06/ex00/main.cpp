/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:23:48 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/30 21:24:30 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (0);
	}
	ScalarConverter sc;
	sc.convert(av[1]);
	return (0);
}
