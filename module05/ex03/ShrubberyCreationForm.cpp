/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:53:56 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/18 18:27:33 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src.getName(), src.getRequiredSign(), src.getRequiredExec())
{
	this->_target = src._target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & src)
{
	if (this == &src)
		return (*this);
	this->_target = src._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream file;
	std::string filename;

	filename = this->_target + "_shrubbery";
	file.open(filename.c_str());
	if (file.is_open())
	{
		file << "      /\\" << std::endl;
		file << "     /  \\" << std::endl;
		file << "    / ^  \\" << std::endl;
		file << "    \\   ^/" << std::endl;
		file << "    /    \\" << std::endl;
		file << "   /    ^ \\" << std::endl;
		file << "   \\      /" << std::endl;
		file << "   /   ^  \\" << std::endl;
		file << "  /  ^     \\" << std::endl;
		file << "  \\________/" << std::endl;
		file << "      ||   " << std::endl;
		file << "      ||   " << std::endl;
		file << "      ||   " << std::endl;
		file << "--------------" << std::endl;
		file << std::endl;
	}
}
