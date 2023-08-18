/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:58:50 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/18 18:03:55 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("defaultform"), _requiredSign(150), _requiredExec(150), _signed(false)
{
}

AForm::AForm(std::string name, int requiredSign, int requiredExec) : _name(name), _requiredSign(requiredSign), _requiredExec(requiredExec), _signed(false)
{
	try
	{
		if (requiredSign < 1 || requiredExec < 1)
			throw GradeTooHighException();
		if (requiredSign > 150 || requiredExec > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}

AForm::AForm(AForm const & src) : _name(src.getName()), _requiredSign(src.getRequiredSign()), _requiredExec(src.getRequiredExec())
{
}

AForm & AForm::operator=(const AForm & src)
{
	if (this == &src)
		return (*this);
	this->_signed = src.getSigned();
	return (*this);
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getRequiredExec() const
{
	return (this->_requiredExec);
}

int AForm::getRequiredSign() const
{
	return (this->_requiredSign);
}

void AForm::beSigned(Bureaucrat & src)
{
	if (src.getGrade() > this->_requiredSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream & operator<<(std::ostream & o, AForm const & src)
{
	o << src.getName() << ", form sign grade " << src.getRequiredSign() << ", exec grade " << src.getRequiredExec() << ", signed: ";
	if (src.getSigned())
		o << "yes";
	else
		o << "no";
	return (o);
}
