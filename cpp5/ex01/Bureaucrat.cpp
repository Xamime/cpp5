/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:38:37 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 16:09:52 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    _grade = ref.getGrade();
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

void    Bureaucrat::signForm(Form & src)
{
    try
    {
        src.beSigned(*this);
    }
    catch (std::exception & e)
    {
        std::cerr <<  _name << " couldn't signed : " << src.getName() << " because :";
        std::cerr << e.what() << '\n';
    }
    if (src.getSign())
        std::cout <<  _name << " signed : " << src.getName() << std::endl;
}


Bureaucrat & Bureaucrat::operator=(Bureaucrat const & ref)
{
    if (this != &ref)
        _grade = ref._grade;
    return *this;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & ref)
{
    o << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
    return o;
}