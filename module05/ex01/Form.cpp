/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:58:50 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/18 15:32:07 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("defaultform"), _requiredSign(150), _requiredExec(150), _signed(false)
{
}

Form::Form(std::string name, int requiredSign, int requiredExec) : _name(name), _requiredSign(requiredSign), _requiredExec(requiredExec), _signed(false)
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

Form::Form(Form const & src) : _name(src.getName()), _requiredSign(src.getRequiredSign()), _requiredExec(src.getRequiredExec())
{
}

Form & Form::operator=(const Form & src)
{
	if (this == &src)
		return (*this);
	this->_signed = src.getSigned();
	return (*this);
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getRequiredExec() const
{
	return (this->_requiredExec);
}

int Form::getRequiredSign() const
{
	return (this->_requiredSign);
}

void Form::beSigned(Bureaucrat & src)
{
	if (src.getGrade() > this->_requiredSign)
		throw GradeTooLowException();
	this->_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream & operator<<(std::ostream & o, Form const & src)
{
	o << src.getName() << ", form sign grade " << src.getRequiredSign() << ", exec grade " << src.getRequiredExec() << ", signed: ";
	if (src.getSigned())
		o << "yes";
	else
		o << "no";
	return (o);
}
