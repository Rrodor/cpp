/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:21:08 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/20 15:25:12 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int		main(void)
{
	Zombie *z = NULL;

	z = z->newZombie("Zombie1");
	z->announce();
	z->randomChump("Zombie2");
	delete z;
	return (0);
}
