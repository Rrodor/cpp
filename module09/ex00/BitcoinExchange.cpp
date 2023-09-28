/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:10:34 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/28 18:57:29 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool dateCompare::operator()(const int* a, const int* b) const
{
	for (int i = 0; i < 3; ++i)
	{
		if (a[i] < b[i])
			return true;
		else if (a[i] > b[i])
			return false;
	}
	return false;
}

BitcoinExchange::BitcoinExchange()
{
	std::string	line;
	std::ifstream	file("data.csv");
	int	*ndate;
	std::string date;
	float value;

	if (!file.is_open())
	{
		std::cout << "error: cannot find data" << std::endl;
		return;
	}
	getline(file, line);
	while (getline(file, line))
	{
		line.append(",");
		date = strtok((char*)line.c_str(), ",");
		value = std::atof(strtok(NULL, ","));
		date.append("-");
		ndate = new int[3];
		ndate[0] = std::atoi(strtok((char*)date.c_str(), "-"));
		ndate[1] = std::atoi(strtok(NULL, "-"));
		ndate[2] = std::atoi(strtok(NULL, "-"));
		this->_data.insert(std::make_pair<int*, float>(ndate, value));
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & ref) : _data(ref.getData())
{
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & ref)
{
	if (this->_data != ref.getData())
		this->_data = ref.getData();
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	for (std::map<int*, float>::iterator it = this->_data.begin(); it != this->_data.end(); it++)
	{
		delete [] it->first;
	}
}

std::map<int*, float, dateCompare> BitcoinExchange::getData() const
{
	return (this->_data);
}

void BitcoinExchange::findDate(std::string date, float n)
{
	int	*ndate = new int [3];
	std::string sdate = date;
	ndate[0] = std::atoi(strtok((char*)date.c_str(), "-"));
	ndate[1] = std::atoi(strtok(NULL, "-"));
	ndate[2] = std::atoi(strtok(NULL, "-"));
	if (n < 0)
	{
		std::cout << "Error: not a positive member." << std::endl;
		delete [] ndate;
		return ;
	}
	if (this->_data[ndate] != 0)
	{
		std::cout << sdate << " => " << n << " = ";
		std::cout << n * this->_data[ndate] << std::endl;
		delete [] ndate;
		return ;
	}
	if (ndate[1] < 13 && ndate[1] > 0 && ndate[2] < 32 && ndate[2]> 0)
	{
		if (n < 0)
		{
			std::cout << "Error: not a positive member." << std::endl;
			delete [] ndate;
		}
		else
		{
			while (this->_data[ndate] == 0 && (ndate[0] > 2008))
			{
				if (ndate[0] < 2010)
				{
					std::cout << sdate << " => " << n << " = ";
					std::cout << '0' << std::endl;
					return ;
				}
				else if (ndate[0] == 2010 && ndate[1] < 8)
				{
					std::cout << sdate << " => " << n << " = ";
					std::cout << '0' << std::endl;
					return ;
				}
				else if (ndate[0] == 2010 && ndate[1] == 8 && ndate[2] <= 19)
				{
					std::cout << sdate << " => " << n << " = ";
					std::cout << '0' << std::endl;
					return ;
				}
				if (ndate[2] == 1)
				{
					if (ndate[1] == 1)
					{
						ndate[0]--;
						ndate[1] = 12;
					}
					else
						ndate[1]--;
					ndate[2] = 31;
				}
				else
					ndate[2]--;
			}
			std::cout << sdate << " => " << n << " = ";
			std::cout << n * this->_data[ndate] << std::endl;
		}
	}
	else
	{
		std::cout << "Error: bad input => " << ndate[0] << "-" << ndate[1] << "-" << ndate[2] << std::endl;
		delete [] ndate;
	}
}

int	BitcoinExchange::ExchangeValue(std::string str)
{
	std::string line;
	std::string date;
	std::string sdate;
	float n;
	std::ifstream	file(str.c_str());
	if (!file.is_open())
	{
		std::cout << "Error : cannot open input file" << std::endl;
		return 0;
	}
	while (getline(file, line))
	{
		if (line.find("|") == std::string::npos)
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			line.append("|");
			date = strtok((char*)line.c_str(), "|");
			n = std::atof(strtok(NULL, "|"));
			if (n > 2147483647.0)
				std::cout << "Error: too large a number." << std::endl;
			else if (date.find("-") != std::string::npos)
				findDate(date, n);
		}
	}
	return 0;
}
