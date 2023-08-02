/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:55:38 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 18:20:45 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "meta->getType() = " << meta->getType() << std::endl;
	std::cout << "j->getType() = " << j->getType() << std::endl;
	std::cout << "i->getType() = " << i->getType() << std::endl;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "---------------------" << std::endl << std::endl;
	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* j2 = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta2->getType() = " << meta2->getType() << std::endl;
	std::cout << "j2->getType() = " << j2->getType() << std::endl;
	std::cout << std::endl;
	j2->makeSound();
	meta2->makeSound();
	std::cout << std::endl;
	delete meta2;
	delete j2;
	return (0);
}
