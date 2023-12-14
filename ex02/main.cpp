/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2023/12/13 16:11:57 by maxime           ###   ########.fr       */
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
    Bureaucrat jean("grade1", 1);
    Bureaucrat toto("grade50", 50);
    Bureaucrat boulard("grade150", 150);
	RobotomyRequestForm robotomy("tommy");
	PresidentialPardonForm pardon("bandito");
	ShrubberyCreationForm myTree("tree");


		
		boulard.signForm(robotomy);
		boulard.signForm(myTree);
		boulard.signForm(pardon);
		toto.signForm(robotomy);
		toto.signForm(myTree);
		toto.signForm(pardon);
		jean.signForm(robotomy);
		jean.signForm(myTree);
		jean.signForm(pardon);
		
		boulard.executeForm(robotomy);
		boulard.executeForm(myTree);
		boulard.executeForm(pardon);
		toto.executeForm(robotomy);
		toto.executeForm(myTree);
		toto.executeForm(pardon);
		jean.executeForm(robotomy);
		jean.executeForm(myTree);
		jean.executeForm(pardon);

		std::cout << "test overload\n";
		std::cout << jean << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << myTree << std::endl;
		std::cout << pardon << std::endl;
	return (0);
}