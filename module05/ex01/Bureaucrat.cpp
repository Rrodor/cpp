/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 14:49:11 by rrodor            #+#    #+#             */
/*   Updated: 2023/08/15 20:24:22 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	*this = src;
}

Bureaucrat::~Bureaucrat( void )
{
}

Bureaucrat &	Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string	const	Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int				Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void			Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void			Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void			Bureaucrat::signForm(Form & form)
{
	if (form.getSigned())
		std::cout << this->_name << " couldn't signed " << form.getName() << " because it is already signed." << std::endl;
	else if (this->_grade > form.getRequiredSign())
		std::cout << this->_name << " couldn't signed " << form.getName() << " because his grade is too low." << std::endl;
	else
	{
		std::cout << this->_name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (o);
}


