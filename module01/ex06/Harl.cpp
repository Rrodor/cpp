/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:00:11 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/25 13:56:47 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	return ;
}

Harl::~Harl()
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG] This is a debug message" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO] This is an info message" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING] This is a warning message" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR] This is an error message" << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	_levels[4] = {"debug", "info", "warning", "error"};
	std::string _funcName[4] = {"debug", "info", "warning", "error"};
	int		i = 0;

	while (level != _levels[i] && i < 4)
		i++;
	switch (i)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break;
		default:
			std::cout << "Invalid level" << std::endl;
			return ;
	}
}
