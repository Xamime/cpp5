/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:38:37 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 16:40:08 by mdesrose         ###   ########.fr       */
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

void    Bureaucrat::signForm(AForm & src)
{
    try
    {
        src.beSigned(*this);
        std::cout <<  _name << " signed : " << src.getName() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr <<  _name << " couldn't signed : " << src.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
}
    
void    Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        std::cout << _name << " try to execute " << form.getName() << " : ";
        form.execute(*this);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
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