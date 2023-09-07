/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:04:54 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/02 15:55:58 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>

class ScalarConverter
{
	private:
		int			_type;
		std::string	_char;
		int			_int;
		float		_float;
		double		_double;
	public:
		ScalarConverter();
		ScalarConverter(std::string str);
		ScalarConverter(ScalarConverter const & src);

		ScalarConverter & operator=(ScalarConverter const & rhs);

		~ScalarConverter();

		void	convert(std::string str);

		std::string	getChar() const;
		int			getInt() const;
		float		getFloat() const;
		double		getDouble() const;
};
