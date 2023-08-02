/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:07:23 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/01 19:18:44 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap P1("P1");
	FragTrap P2("P2");

	P1.attack("ennemy");
	P1.takeDamage(20);
	P1.beRepaired(10);
	P1.guardGate();

	P2.attack("ennemy");
	P2.takeDamage(20);
	P2.beRepaired(10);
	P2.highFivesGuys();
	return (0);
}
