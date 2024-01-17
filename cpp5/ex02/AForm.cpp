/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:36:44 by maxime            #+#    #+#             */
/*   Updated: 2023/12/14 16:59:30 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

const char *AForm::AlreadySign::what(void) const throw()
{
    return ("Form is already sign !");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

const char *AForm::IsnotSigned::what(void) const throw()
{
    return ("Form isn't signed");
}

AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade)
: _name(name), _target(target), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    _is_signed = 0;
}

AForm::AForm(): _name("NULL"), _sign_grade(150), _exec_grade(150)
{
    _is_signed = 0;
}

AForm::AForm(const AForm& src): _name(src.getName()), _sign_grade(src.getSignGrade()), _exec_grade(src.getExecGrade())
{
    _is_signed = src._is_signed;
}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
    {
        _is_signed = src._is_signed;
    }
    return *this;
}

AForm::~AForm()
{
    // TODO: Implement destructor
}

std::string AForm::getName() const
{
    return _name;
}

std::string AForm::getTarget() const
{
    return _target;
}

void AForm::setSign(bool sign)
{
    _is_signed = sign;
}

bool AForm::getSign() const
{
    return _is_signed;
}
    
int AForm::getSignGrade() const
{
    return _sign_grade;
}

int AForm::getExecGrade() const
{
    return _exec_grade;
}
 
void    AForm::beSigned(Bureaucrat & src)
{
    if (_is_signed == 1)
        throw AForm::AlreadySign();
    else if (_sign_grade >= src.getGrade())
        _is_signed = 1;
    else
        throw AForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, AForm & ref)
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
