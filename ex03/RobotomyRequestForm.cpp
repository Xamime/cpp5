/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:11:10 by maxime            #+#    #+#             */
/*   Updated: 2023/12/13 16:10:36 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSign() == 0)
		throw AForm::IsnotSigned();
	if (getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	robotomy();
}

void    RobotomyRequestForm::robotomy() const
{
    std::cout << "Drr.... Drrr ..." << std::endl;
    srand(time(NULL));
    if ((rand() % 2))
        std::cout << getTarget() << " has been robotomized" << std::endl;
    else
        std::cout << "robotomy failed" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", "NULL", 72, 45)
{
    // TODO: Implement constructor
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    // TODO: Implement copy constructor
    (void)other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        // TODO: Implement copy assignment
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // TODO: Implement destructor
}