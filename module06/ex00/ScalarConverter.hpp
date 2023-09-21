/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:04:54 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 16:44:59 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <float.h>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter & operator=(ScalarConverter const & rhs);
		~ScalarConverter();
	public:
		static void	convert(std::string str);
};
