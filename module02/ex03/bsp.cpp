/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:46:16 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/30 02:05:52 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = (point.x - b.x) * (a.y - b.y) - (a.x - b.x) * (point.y - b.y);
	Fixed B = (point.x - c.x) * (b.y - c.y) - (b.x - c.x) * (point.y - c.y);
	Fixed C = (point.x - a.x) * (c.y - a.y) - (c.x - a.x) * (point.y - a.y);

	if (A < 0 && B < 0 && C < 0)
		return (true)
	else if (A > 0 && B > 0 && C > 0)
		return (true)
	else
		return (false)
}

