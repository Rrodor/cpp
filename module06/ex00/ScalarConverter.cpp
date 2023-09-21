/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:43:02 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 13:57:09 by rrodor           ###   ########.fr       */
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

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
	*this = rhs;
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	int i = 0;
	std::string tmp = "'";
	int	type;
	int	_int;
	float _float;
	double _double;
	std::string _char;

	if (std::isprint(str[0]) && !std::isdigit(str[0]))
	{
		if (str.length() == 1)
			type = TCHAR;
		else if (str == "nan")
			type = NAN;
		else if (str == "+inf")
			type = MAXINF;
		else if (str == "-inf")
			type = MININF;
		else
			type = ERROR;
	}
	else if (*(str.end()) == 'f')
	{
		str = str.substr(0, str.size()-1);
		while (isdigit(str[i]) || str[i] == '.')
			i++;
		if (i == static_cast<int>(str.length()))
			type = TFLOAT;
		else
			type = ERROR;
	}
	else if (str.find('.') != std::string::npos)
	{
		while (isdigit(str[i]) || str[i] == '.')
			i++;
		if (i == static_cast<int>(str.length()))
			type = TDOUBLE;
		else
			type = ERROR;
	}
	else if (isdigit(str[0]))
	{
		while (isdigit(str[i]))
			i++;
		if (i == static_cast<int>(str.length()))
			type = TINT;
		else
			type = ERROR;
	}
	else
		type = ERROR;

	switch (type)
	{
		case TCHAR:
			_char = tmp + str[0] + tmp;
			_int = static_cast<int>(str[0]);
			_float = static_cast<float>(str[0]);
			_double = static_cast<double>(str[0]);
			break;
		case TINT:
			_int = std::atoi(str.c_str());
			_float = static_cast<float>(_int);
			_double = static_cast<double>(_int);
			if (_int < 0 || _int > 127)
				_char = "impossible";
			else if (_int < 32 || _int == 127)
				_char = "Non displayable";
			else
				_char = tmp + static_cast<char>(_int) + tmp;
			break;
		case TFLOAT:
			_float = std::atof(str.c_str());
			_int = static_cast<int>(_float);
			_double = static_cast<double>(_float);
			if (_float < 0 || _float > 127)
				_char = "impossible";
			else if (_float < 32 || _float == 127)
				_char = "Non displayable";
			else
				_char = tmp +  static_cast<char>(_float) + tmp;
			break;
		case TDOUBLE:
			_double = std::atof(str.c_str());
			_int = static_cast<int>(_double);
			_float = static_cast<float>(_double);
			if (_double < 0 || _double > 127)
				_char = "impossible";
			else if (_double < 32 || _double == 127)
				_char = "Non displayable";
			else
				_char = tmp + static_cast<char>(_double) + tmp;
			break;
		case ERROR:
			_char = "impossible";
			_int = 0;
			_float = 0;
			_double = 0;
			break;
		case NAN:
			_char = "impossible";
			_int = 0;
			_float = 0;
			_double = 0;
			break;
		case MININF:
			_char = "impossible";
			_int = -2147483648;
			_float = -FLT_MAX;
			_double = -DBL_MAX;
			break;
		case MAXINF:
			_char = "impossible";
			_int = 247483647;
			_float = FLT_MAX;
			_double = DBL_MAX;
		default:
			break;
	}

	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << _float << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << _double << std::endl;

}

