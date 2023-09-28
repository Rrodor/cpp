/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:35:59 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/25 15:02:47 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <algorithm>
#include <string>
#include <string.h>
#include <fstream>
#include <iostream>

struct dateCompare
{
	bool operator()(const int* a, const int* b) const;
};

class BitcoinExchange
{
	private:
		std::map<int*, float, dateCompare>	_data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & ref);
		BitcoinExchange & operator=(const BitcoinExchange & ref);
		~BitcoinExchange();

		std::map<int*, float, dateCompare>	getData() const;
		int	ExchangeValue(std::string str);
		void findDate(std::string date, float value);
		//int convert(std::string date, float n);
};
