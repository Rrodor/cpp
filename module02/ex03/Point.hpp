/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:35:46 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/30 01:41:05 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	private
		Fixed const x;
		Fixed const y;
	public
		Point();
		Point(Fixed const x, Fixed const, y);
		Point(Point const &p);
		Point & operator=(Point const &rhs);
		~Point();
		
}
