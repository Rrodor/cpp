/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:26:25 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 15:45:59 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main()
{
	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(700);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::vector<int>	vec = sp.getSpan();
	std::cout << "vector is : ";
	for (unsigned int i = 0; i < sp.getSize(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;

	std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "longest span = " << sp.longestSpan() << std::endl;

	std::vector<int>	v = sp.getSpan();

	std::cout << "vector is : ";
	for (unsigned int i = 0; i < sp.getSize(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;

	Span sp2 = Span(10000);
	std::vector<int> vc;
	for (int i = 0; i < 10000; i++)
		vc.push_back(i);
	sp2.addRange(vc.begin(),vc.end());
	std::vector<int>	vec2 = sp2.getSpan();
	std::cout << "new vector is : ";
	for (unsigned int i = 0; i < sp2.getSize(); i++)
		std::cout << vec2[i] << " ";
	std::cout << std::endl;
	return 0;
}
