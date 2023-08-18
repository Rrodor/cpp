/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:58:19 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/18 15:35:34 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat *boss;
	Bureaucrat *slave;
	Form *contract;


	try
	{
		contract = new Form("Contract", 0, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete contract;

	try
	{
		contract = new Form("Contract", 156, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete contract;

	try
	{
		contract = new Form("Contract", 10, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete contract;

	try
	{
		contract = new Form("Contract", 10, 156);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	delete contract;

	try
	{
		boss = new Bureaucrat("Boss", 1);
		std::cout << *boss << std::endl;
		slave = new Bureaucrat("Slave", 150);
		std::cout << *slave << std::endl;
		contract = new Form("Contract", 10, 10);
		std::cout << *contract << std::endl;
		slave->signForm(*contract);
		boss->signForm(*contract);
		boss->signForm(*contract);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete boss;
	delete slave;
	delete contract;
}
