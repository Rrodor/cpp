/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 21:23:48 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 13:38:31 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iomanip>

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [string]" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
