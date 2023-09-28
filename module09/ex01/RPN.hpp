/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:58:43 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/25 18:55:47 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <algorithm>

class RPN
{
	private:
		RPN();
		RPN(const RPN & ref);
		RPN & operator=(const RPN & ref);
		~RPN();
	public:
		static std::string	testRPN(std::string str);
		static void			calculate(std::string str);
};
