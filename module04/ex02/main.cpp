/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:55:38 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/02 20:22:39 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* Animals[10];
	for (int i = 0; i < 5; i++)
		Animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		Animals[i] = new Cat();
	for (int i = 0; i < 10; i++)
		Animals[i]->makeSound();
	for (int i = 0; i < 10; i++)
	{
		delete Animals[i];
	}
}
