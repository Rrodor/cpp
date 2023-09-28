/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:06:05 by rrodor            #+#    #+#             */
/*   Updated: 2023/09/25 20:17:29 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(const RPN & ref)
{
	(void)ref;
}

RPN & RPN::operator=(const RPN & ref)
{
	(void)ref;
	return (*this);
}

RPN::~RPN()
{
}

std::string	RPN::testRPN(std::string str)
{
	char *line = (char *)str.c_str();
	std::string::iterator it;
	int n = 0;
	int s = 0;
	int space = 1;
	if (line[0] < '0' || line[0] > '9')
		return ("NULL");
	for (int i = 0; line[i]; i++)
	{
		if (line[i] < '0' || line[i] > '9')
		{
			if (line[i] != '+' && line[i] != '-' && line[i] != '*' && line[i] != '/' && line[i] != ' ')
				return ("NULL");
			else if (line[i] == ' ' && space == 0)
				space += 1;
			else if (line[i] == ' ' && space == 1)
				return ("NULL");
			else if (space == 0)
				return ("NULL");
			else
			{
				s++;
				space -= 1;
			}
		}
		else if (space == 1)
		{
			n++;
			space -= 1;
		}
		else
			return ("NULL");
	}
	if (n == s + 1)
		return (str);
	return ("NULL");
}

void RPN::calculate(std::string str)
{
	str = testRPN(str);
	int	i = 0;
	int	n;
	std::stack<int> s;

	if (str == "NULL")
	{
		std::cout << "Error" << std::endl;
		return ;
	}
	char *line = (char *)str.c_str();

	s.push(line[i] - 48);
	i += 2;

	while (line[i])
	{
		if (line[i] == ' ')
			i++;
		else if (line[i] < 58 && line[i] > 47)
		{
			if (line[i + 1] && line[i + 2] && line[i + 2] < 58 && line[i + 2] > 47)
			{
				s.push(line[i] - 48);
				i++;
			}
			else if (line[i + 1] && line[i + 2] && line[i + 2] == ' ')
				std::cout <<"error" << std::endl;
			else if (line[i + 1] && line[i + 2])
			{
				if (line[i + 2] == '+')
					s.top() += line[i] - 48;
				if (line[i + 2] == '-')
					s.top() -= line[i] - 48;
				if (line[i + 2] == '*')
					s.top() *= line[i] - 48;
				if (line[i + 2] == '/')
					s.top() /= line[i] - 48;
				i += 3;
			}
		}
		else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] != '/')
		{
			n = s.top();
			s.pop();
			if (line[i] == '+')
				s.top() += n;
			if (line[i] == '-')
				s.top() -= n;
			if (line[i] == '*')
				s.top() *= n;
			if (line[i] == '/')
				s.top() /= n;
			i++;
		}
	}
	std::cout << s.top() << std::endl;
}
