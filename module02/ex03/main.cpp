/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:14:14 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/30 02:11:38 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a1(0, 0);
	Point b1(3, 0);
	point c1(0, 3);
	point t1(1, 1);
	point t2(3, 3);


	if (bsp(a1, b1, c1, t1))
		std::cout << "valid" << std::endl;
	else
		std::cout << "false" << std::endl;

	if (bsp(a1, b1, c1, t2))
		std::cout << "valid" << std::endl;
	else
		std::cout << "false" << std::endl;

	return 0;
}
