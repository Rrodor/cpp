/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:29:37 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/25 12:39:55 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	BitcoinExchange btc;
	(void)argv;

	if (argc != 2)
		std::cout << "Error: could not open file" << std::endl;
	else
		btc.ExchangeValue(argv[1]);
	return 0;
}
