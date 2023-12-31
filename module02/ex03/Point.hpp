/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:35:46 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/01 14:53:40 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &p);
		Point & operator=(Point &rhs);
		~Point();
		Fixed	getPointx(void) const;
		Fixed	getPointy(void) const;
};
