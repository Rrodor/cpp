/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:43:02 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/30 21:28:45 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define TCHAR		0
#define TINT		1
#define TFLOAT		2
#define TDOUBLE		3
#define ERROR		4

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(std::string str)
{
}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_str = rhs._str;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	int i = 0;

	if (std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		if (str.length() == 1)
			this->_type = TCHAR;
		else
			this->_type = ERROR;
	}
	else if (str.back() == 'f')
	{
		str.pop_back();
		while (isdigit(str[i]) || str[i] == '.')
			i++;
		if (i == str.length())
			this->_type = TFLOAT;
		else
			this->_type = ERROR;
	}
	else if (str.find('.') != std::string::npos)
	{
		while (isdigit(str[i]) || str[i] == '.')
			i++;
		if (i == str.length())
			this->_type = TDOUBLE;
		else
			this->_type = ERROR;
	}
	else if (isdigit(str[0]))
	{
		while (isdigit(str[i]))
			i++;
		if (i == str.length())
			this->_type = TINT;
		else
			this->_type = ERROR;
	}
	std::cout << _type << std::endl;
	/*switch (this->_type)
	{
		case TCHAR:
			THIS->_str = str[0];
			this->_int = static_cast<int>(str[0]);
			this->_float = static_cast<float>(str[0]);
			this->_double = static_cast<double>(str[0]);
			break;
		case TINT:
			this->_int = std::stoi(str);
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
			break;
		case TFLOAT:
			this->_float = std::stof(str);
			this->_int = static_cast<int>(this->_float);
			this->_double = static_cast<double>(this->_float);
			break;
		case TDOUBLE:
			this->_double = std::stod(str);
			this->_int = static_cast<int>(this->_double);
			this->_float = static_cast<float>(this->_double);
			break;
		default:
			break;
	}*/
}
