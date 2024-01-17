/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:36:44 by maxime            #+#    #+#             */
/*   Updated: 2023/12/13 15:48:04 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char *Form::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *Form::AlreadySign::what(void) const throw()
{
    return ("Form is already sign !");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

Form::Form(): _name("NULL"), _sign_grade(150), _exec_grade(150)
{
    _is_signed = 0;
}

Form::Form(std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    _is_signed = 0;
}

Form::Form(const Form& src): _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
    _is_signed = src._is_signed;
}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
    {
        _is_signed = src._is_signed;
    }
    return *this;
}

Form::~Form()
{
    // TODO: Implement destructor
}

std::string Form::getName() const
{
    return _name;
}

void Form::setSign(bool sign)
{
    _is_signed = sign;
}

bool Form::getSign() const
{
    return _is_signed;
}
    
int Form::getSignGrade() const
{
    return _sign_grade;
}

int Form::getExecGrade() const
{
    return _exec_grade;
}
 
void    Form::beSigned(Bureaucrat & src)
{
    if (_is_signed == 1)
        throw Form::AlreadySign();
    else if (_sign_grade >= src.getGrade())
        _is_signed = 1;
    else
        throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form & ref)
{
    o << "Form name : " << ref.getName() << std::endl;
    if (ref.getSign())
        o << "The form is signed" << std::endl;
    else
        o << "The form is not signed" << std::endl;
    o << "Grade required to sign : " << ref.getSignGrade() << std::endl;
    o << "Grade required to execute : " << ref.getExecGrade();
    return o;
}

