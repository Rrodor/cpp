/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:20:02 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/21 14:28:42 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <stdlib.h>
#include <stdexcept>
#include <iostream>

Base	*generate(void)
{
	int	type = rand() % 3;

	switch (type)
	{
		case 0:
			return (new A);
			break;
		case 1:
			return (new B);
			break;
		default:
			return (new C);
			break;
	}
}

void	identify(Base *p)
{
	A	*derivA;
	B	*derivB;
	C	*derivC;

	derivA = dynamic_cast<A *>(p);
	derivB = dynamic_cast<B *>(p);
	derivC = dynamic_cast<C *>(p);
	if (derivA)
		std::cout << "pointer identifier: this is a type A" << std::endl;
	else if (derivB)
		std::cout << "pointer identifier: this is a type B" << std::endl;
	else if (derivC)
		std::cout << "pointer identifier: this is a type C" << std::endl;
	else
		std::cout << "pointer identifier: error" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&derivA = dynamic_cast<A &>(p);
		(void)derivA;
		std::cout << "reference identifier: this is a type A" << std::endl;
	}
	catch(std::exception &e)
	{
	}

	try
	{
		B	&derivB = dynamic_cast<B &>(p);
		(void)derivB;
		std::cout << "reference identifier: this is a type B" << std::endl;
	}
	catch(std::exception &e)
	{
	}

	try
	{
		C	&derivC = dynamic_cast<C &>(p);
		(void)derivC;
		std::cout << "reference identifier: this is a type C" << std::endl;
	}
	catch(std::exception &e)
	{
	}
}

int	main()
{
	Base	*test;
	srand(time(NULL));

	test = generate();
	identify(test);
	identify(*test);
	delete test;
	return (0);
}
