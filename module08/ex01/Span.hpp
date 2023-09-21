/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:14:32 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 15:34:58 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stdexcept>

class Span
{
	private:
		std::vector<int>	_span;
		unsigned int		_sizeMax;
		unsigned int		_size;
	public:
		Span();
		Span(const Span & ref);
		Span & operator=(const Span & ref);
		~Span();

		Span(unsigned int n);
		void	addNumber(int n);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator last);
		int		shortestSpan();
		int		longestSpan();

		std::vector<int>	getSpan() const;
		unsigned int		getSize() const;
		unsigned int		getSizeMax() const;

		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};
