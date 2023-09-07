/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:43:02 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/02 16:01:19 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#define TCHAR		0
#define TINT		1
#define TFLOAT		2
#define TDOUBLE		3
#define ERROR		4
#define NAN			5
#define MININF		6
#define MAXINF		7

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
		this->_char = rhs._char;
		this->_int = rhs._int;
		this->_float = rhs._float;
		this->_double = rhs._double;
	}
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	int i = 0;
	std::string tmp = "'";

	if (std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		if (str.length() == 1)
			this->_type = TCHAR;
		else if (str == "nan")
			this->_type = NAN;
		else if (str == "+inf")
			this->_type = MAXINF;
		else if (str == "-inf")
			this->_type = MININF;
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
	else
		this->_type = ERROR;

	switch (this->_type)
	{
		case TCHAR:
			this->_char = tmp + str[0] + tmp;
			this->_int = static_cast<int>(str[0]);
			this->_float = static_cast<float>(str[0]);
			this->_double = static_cast<double>(str[0]);
			break;
		case TINT:
			this->_int = std::stoi(str);
			this->_float = static_cast<float>(this->_int);
			this->_double = static_cast<double>(this->_int);
			if (this->_int < 0 || this->_int > 127)
				this->_char = "impossible";
			else if (this->_int < 32 || this->_int == 127)
				this->_char = "Non displayable";
			else
				this->_char = tmp + static_cast<char>(this->_int) + tmp;
			break;
		case TFLOAT:
			this->_float = std::stof(str);
			this->_int = static_cast<int>(this->_float);
			this->_double = static_cast<double>(this->_float);
			if (this->_float < 0 || this->_float > 127)
				this->_char = "impossible";
			else if (this->_float < 32 || this->_float == 127)
				this->_char = "Non displayable";
			else
				this->_char = tmp +  static_cast<char>(this->_float) + tmp;
			break;
		case TDOUBLE:
			this->_double = std::stod(str);
			this->_int = static_cast<int>(this->_double);
			this->_float = static_cast<float>(this->_double);
			if (this->_double < 0 || this->_double > 127)
				this->_char = "impossible";
			else if (this->_double < 32 || this->_double == 127)
				this->_char = "Non displayable";
			else
				this->_char = tmp + static_cast<char>(this->_double) + tmp;
			break;
		case ERROR:
			this->_char = "impossible";
			this->_int = 0;
			this->_float = 0;
			this->_double = 0;
			break;
		case NAN:
			this->_char = "impossible";
			this->_int = 0;
			this->_float = 0;
			this->_double = 0;
			break;
		case MININF:
			this->_char = "impossible";
			this->_int = -2147483648;
			this->_float = -FLT_MAX;
			this->_double = -DBL_MAX;
			break;
		case MAXINF:
			this->_char = "impossible";
			this->_int = 247483647;
			this->_float = FLT_MAX;
			this->_double = DBL_MAX;
		default:
			break;
	}

	std::cout << "char: " << this->_char << std::endl;
	std::cout << "int: " << this->_int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << this->_float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << this->_double << std::endl;
}

std::string	ScalarConverter::getChar() const
{
	return (this->_char);
}

int			ScalarConverter::getInt() const
{
	return (this->_int);
}

float		ScalarConverter::getFloat() const
{
	return (this->_float);
}

double		ScalarConverter::getDouble() const
{
	return (this->_double);
}
