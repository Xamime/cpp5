/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2023/12/14 11:24:15 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void)
{		
	Intern someRandomIntern;
	Bureaucrat jean("grade50", 45);
	AForm* rrf;
	std::string form[3] = {
		"shruberry creation",
        "robotomy request",
        "presidential pardon"};
	try
	{
		rrf = someRandomIntern.makeForm(form[1], "Bender");
		jean.signForm(*rrf);
		jean.executeForm(*rrf);
		delete rrf;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}