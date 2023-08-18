/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:58:19 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/18 19:14:51 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm	*shru = new ShrubberyCreationForm("forest");
	AForm	*robo = new RobotomyRequestForm("robot");
	AForm	*pres = new PresidentialPardonForm("president");
	Bureaucrat *b = new Bureaucrat("Bob", 1);
	Bureaucrat *b2 = new Bureaucrat("Bob2", 150);

	std::cout << *b << std::endl;
	std::cout << *b2 << std::endl;
	std::cout << *shru << std::endl;
	std::cout << *robo << std::endl;
	std::cout << *pres << std::endl;

	b->executeForm(*shru);
	b->signForm(*shru);
	b->executeForm(*shru);
	b->signForm(*robo);
	b->executeForm(*robo);
	b->signForm(*pres);
	b->executeForm(*pres);

	b2->signForm(*shru);
	b2->executeForm(*shru);
	b2->signForm(*robo);
	b2->executeForm(*robo);
	b2->signForm(*pres);
	b2->executeForm(*pres);

	delete shru;
	delete robo;
	delete pres;
	delete b;
	delete b2;
}
