/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:00:11 by rrodor            #+#    #+#             */
/*   Updated: 2023/07/22 19:17:16 by rrodor           ###   ########.fr       */
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
	void		(Harl::*funcPTR)(void) = NULL;
	void		(Harl::*_funcPTR[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	_levels[4] = {"debug", "info", "warning", "error"};


	for (int i = 0; i < 4; i++)
	{
		if (level == _levels[i])
			funcPTR = _funcPTR[i];
	}
	if (!funcPTR)
	{
		std::cout << "Invalid level" << std::endl;
		return ;
	}
	(this->*funcPTR)();
}
