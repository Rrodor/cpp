/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:07:23 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/01 19:14:07 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap P1("P1");

	P1.attack("ennemy");
	P1.takeDamage(20);
	P1.beRepaired(10);
	P1.guardGate();
	return (0);
}
