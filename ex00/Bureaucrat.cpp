/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:38:37 by maxime            #+#    #+#             */
/*   Updated: 2023/12/11 06:12:44 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("null")
{
    _grade = 0;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const & ref): _name(ref.getName())
{
    *this = ref; 
}

void    Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << _name << " grade " << _grade << " destroyed !" << std::endl;
}

const std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::GradeUp()
{
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade -= 1;
}

void    Bureaucrat::GradeDown()
{
    if (this->_grade + 1 >= 151)
        throw Bureaucrat::GradeTooLowException();
    this->_grade += 1;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
    if (this == &ref)
		return *this;
        
    _grade = ref._grade;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & ref)
{
    o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
    return o;
}