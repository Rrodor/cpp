/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:37:45 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/20 19:07:45 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "test with MutantStack" << std::endl;
	MutantStack<int> mstack;

	std::cout << "add 5 and 17" << std::endl;
	mstack.push(5);
	mstack.push(17);

	std::cout << "top = " << mstack.top() << std::endl;

	std::cout << "pop" << std::endl;
	mstack.pop();

	std::cout << "size = " << mstack.size() << std::endl;

	std::cout << "add 3, 5, 737 and 0" << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "top = " << mstack.top() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);




	std::cout << std::endl << std::endl << std::endl;
	std::cout << "test with list" << std::endl;
	std::list<int> list;

	std::cout << "add 5 and 17" << std::endl;
	list.push_front(5);
	list.push_front(17);

	std::cout << "top = " << list.front() << std::endl;

	std::cout << "pop" << std::endl;
	list.pop_front();

	std::cout << "size = " << list.size() << std::endl;

	std::cout << "add 3, 5, 737 and 0" << std::endl;
	list.push_front(3);
	list.push_front(5);
	list.push_front(737);
	list.push_front(0);

	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lite = list.end();

	++lit;
	--lit;

	while (lit != lite)
	{
		lite--;
		std::cout << *lite << std::endl;
	}

	std::list<int> l(list);

	return 0;

	return 0;
}

