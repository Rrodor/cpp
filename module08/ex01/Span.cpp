/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:25:37 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/18 23:07:04 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
}

Span::Span(const Span & ref)
{
	this->_span = ref.getSpan();
	this->_sizeMax = ref.getSizeMax();
	this->_size = ref.getSize();
}

Span & Span::operator=(const Span & ref)
{
	if (this->_span != ref.getSpan() && this->_sizeMax >= ref.getSize())
	{
		this->_span = ref.getSpan();
		this->_size = ref.getSize();
	}
	else
		std::cout << "incompatible Span size" << std::endl;
	return (*this);
}

Span::~Span()
{
}

Span::Span(unsigned int n)
{
	this->_sizeMax = n;
	this->_size = 0;
}

std::vector<int>	Span::getSpan() const
{
	return (this->_span);
}

unsigned int	Span::getSize() const
{
	return (this->_size);
}

unsigned int	Span::getSizeMax() const
{
	return (this->_sizeMax);
}

void	Span::addNumber(int n)
{
	if (_size == _sizeMax)
		throw Span::FullSpanException();
	else
	{
		_span.push_back(n);
		_size++;
	}
}

void	Span::addRange(int begin, int end)
{
	if (end < begin)
	{
		std::cout << "Error: invalid order" << std::endl;
	}
	if (abs(end - begin) > _sizeMax - _size)
	{
		std::cout << "Error: Array is full" << std::endl;
		return ;
	}
	std::vector<int> vec(end - begin);
	std::iota(vec.begin(), vec.end(), begin);
	_span.insert(_span.end(), vec.begin(), vec.end());
	_size += end - begin;
}

int		Span::shortestSpan()
{
	std::vector<int>	vec(this->_span);
	int					t = 2147483647;

	sort(vec.begin(), vec.end());
	for (int i = 0; i + 1 !=  vec.size(); i++)
	{
		if (abs(vec[i] - vec[i + 1]) < t)
			t = abs(vec[i] - vec[i + 1]);
	}
	return (t);
}

int		Span::longestSpan()
{
	return (*max_element(_span.begin(), _span.end()) - *min_element(_span.begin(), _span.end()));
}

const char* Span::FullSpanException::what() const throw()
{
	return ("the Span is full");
}
