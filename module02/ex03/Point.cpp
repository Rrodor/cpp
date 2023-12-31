/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 02:12:18 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/01 14:52:53 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void)
{
}

Point::Point(float const a, float const b) : x(a), y(b)
{
}

Point::Point(Point const &p) : x(p.getPointx()), y(p.getPointy())
{
}

Point & Point::operator=(Point &rhs)
{
	return (rhs);
}

Point::~Point()
{
}

Fixed	Point::getPointx(void) const
{
	return this->x;
}

Fixed	Point::getPointy(void) const
{
	return this->y;
}
