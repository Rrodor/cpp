/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 15:42:20 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/20 15:57:49 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	Zombie *z = NULL;

	z = z->zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		z[i].announce();
	std::cout << "delete z" << std::endl;
	delete [] z;
	return (0);
}
