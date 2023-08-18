/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:58:19 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/18 20:40:10 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm	*shru;
	AForm	*robo;
	AForm	*pres;
	AForm	*form;
	Intern	*intern = new Intern();
	Bureaucrat *b = new Bureaucrat("Bob", 1);
	Bureaucrat *b2 = new Bureaucrat("Bob2", 150);

	shru = intern->makeForm("shrubbery creation", "forest");
	robo = intern->makeForm("robotomy request", "robot");
	pres = intern->makeForm("presidential pardon", "president");
	form = intern->makeForm("nonexistantform", "someone");

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
	delete form;
	delete intern;
	delete b;
	delete b2;
}
