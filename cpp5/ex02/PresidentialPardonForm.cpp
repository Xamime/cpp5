/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:11:01 by maxime            #+#    #+#             */
/*   Updated: 2023/12/13 16:10:46 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", "NULL", 25, 5)
{
}


PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", target, 25, 5)
{
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == 0)
		throw AForm::IsnotSigned();
	if (getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
    // TODO: Implement copy constructor
    (void)other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        // TODO: Implement copy assignment
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    // TODO: Implement destructor
}