/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:46:16 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/01 15:09:43 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed A = (point.getPointx() - b.getPointx()) * (a.getPointy() - b.getPointy()) - (a.getPointx() - b.getPointx()) * (point.getPointy() - b.getPointy());
	Fixed B = (point.getPointx() - c.getPointx()) * (b.getPointy() - c.getPointy()) - (b.getPointx() - c.getPointx()) * (point.getPointy() - c.getPointy());
	Fixed C = (point.getPointx() - a.getPointx()) * (c.getPointy() - a.getPointy()) - (c.getPointx() - a.getPointx()) * (point.getPointy() - a.getPointy());

	if (A < 0 && B < 0 && C < 0)
		return (true);
	else if (A > 0 && B > 0 && C > 0)
		return (true);
	else
		return (false);
}

