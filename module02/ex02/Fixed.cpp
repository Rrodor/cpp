/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 17:49:15 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/30 01:29:40 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::Fixed(int const n)
{
	this->fixedPointValue = n << fractionalBits;
}

Fixed::Fixed(float const n)
{
	this->fixedPointValue = roundf(n * (1 << fractionalBits));
}

Fixed::~Fixed()
{
}

Fixed::Fixed(Fixed const & src)
{;
	*this = src;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
		this->fixedPointValue = rhs.getRawBits();
	return *this;
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return this->fixedPointValue > rhs.getRawBits();
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return this->fixedPointValue < rhs.getRawBits();
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return this->fixedPointValue >= rhs.getRawBits();
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return this->fixedPointValue <= rhs.getRawBits();
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return this->fixedPointValue == rhs.getRawBits();
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return this->fixedPointValue != rhs.getRawBits();
}

Fixed	Fixed::operator+(Fixed const & rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const & rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed &	Fixed::operator++(void)
{
	this->fixedPointValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed &	Fixed::operator--(void)
{
	this->fixedPointValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

int		Fixed::getRawBits(void) const
{
	return this->fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return (float)this->fixedPointValue / (float)(1 << fractionalBits);
}

int		Fixed::toInt(void) const
{
	return this->fixedPointValue >> fractionalBits;
}

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	return a < b ? a : b;
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	return a > b ? a : b;
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	return a < b ? a : b;
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	return a > b ? a : b;
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return o;
}
