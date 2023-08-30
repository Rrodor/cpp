/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:04:54 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/30 20:44:07 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ScalarConverter
{
	private:
		int			_type;
		std::string	_str;
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
};
