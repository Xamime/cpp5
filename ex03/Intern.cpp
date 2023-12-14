/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:11:07 by maxime            #+#    #+#             */
/*   Updated: 2023/12/14 11:23:10 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const char *Intern::FormatException::what(void) const throw()
{
    return ("Can't recognize the form's name !");
}

static AForm * robot(std::string target)
{
    return new RobotomyRequestForm(target);
}

static AForm * pardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

static AForm * tree(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm * Intern::makeForm(std::string form, std::string target)
{
    AForm *(*ptr[3])(std::string target) = {&tree, &robot, &pardon};
    std::string list[3] = {
        "shruberry creation",
        "robotomy request",
        "presidential pardon"
    };
    for (int i = 0; i < 3; i++)
    {
        if (form == list[i])
            return (ptr[i](target));
    }
    throw Intern::FormatException();
    return (NULL);
}

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {
    }
    return *this;
}

Intern::~Intern()
{
    
}