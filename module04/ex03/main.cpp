/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:57:34 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/09 00:13:19 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << "test for ice and cure :" << std::endl << std::endl;
	AMateria *a = new Ice();
	AMateria *b = a->clone();
	AMateria *c = new Cure();
	AMateria *d = c->clone();

	std::cout << "a type : " << a->getType() << std::endl;
	std::cout << "b type : " << b->getType() << std::endl;
	std::cout << "c type : " << c->getType() << std::endl;
	std::cout << "d type : " << d->getType() << std::endl;

	delete a;
	delete b;
	delete c;
	delete d;

	std::cout << std::endl <<std::endl;

	std::cout << "test for character" << std::endl << std::endl;
	ICharacter *p1 = new Character("Victor Von Doom");

	AMateria *frostspell1 = new Ice();
	AMateria *frostspell2 = new Ice();
	AMateria *frostspell3 = new Cure();
	AMateria *frostspell4 = new Cure();
	AMateria *frostspell5 = new Cure();
	p1->equip(frostspell1);
	p1->equip(frostspell2);
	p1->equip(frostspell3);
	p1->equip(frostspell4);
	p1->equip(frostspell5);
	p1->unequip(2);
	p1->unequip(5);

	ICharacter *p2 = new Character("Doombot");

	//delete p2;
	*p2 = *p1;
	p2->equip(frostspell5);

	p1->use(1, *p2);
	p1->use(3, *p2);
	p1->use(8, *p2);
	p1->use(2, *p2);

	delete p1;
	delete p2;
	delete frostspell3;


	std::cout << std::endl <<std::endl;

	std::cout << "test from subject" << std::endl << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);

	delete bob;
	delete me;
	delete src;

	return (0);
}
