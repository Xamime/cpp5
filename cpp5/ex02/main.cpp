/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 16:52:22 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat grade1("grade1", 1);
    Bureaucrat grade50("grade50", 50);
    Bureaucrat grade150("grade150", 150);
	RobotomyRequestForm robotomy("tommy");
	PresidentialPardonForm pardon("bandito");
	ShrubberyCreationForm myTree("tree");


		std::cout << "\ntest signForm\n\n";
		
		grade150.signForm(robotomy);
		grade150.signForm(myTree);
		grade150.signForm(pardon);
		grade50.signForm(robotomy);
		grade50.signForm(myTree);
		grade50.signForm(pardon);
		grade1.signForm(robotomy);
		grade1.signForm(myTree);
		grade1.signForm(pardon);
		
		std::cout << "\ntest executeForm\n\n";

		grade150.executeForm(robotomy);
		grade150.executeForm(myTree);
		grade150.executeForm(pardon);
		grade50.executeForm(robotomy);
		grade50.executeForm(myTree);
		grade50.executeForm(pardon);
		grade1.executeForm(robotomy);
		grade1.executeForm(myTree);
		grade1.executeForm(pardon);

		std::cout << "\ntest overload\n\n";
		std::cout << grade1 << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << myTree << std::endl;
		std::cout << pardon << std::endl;

	return (0);
}