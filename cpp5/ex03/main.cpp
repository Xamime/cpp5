/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 17:10:04 by mdesrose         ###   ########.fr       */
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
		rrf = someRandomIntern.makeForm(form[2], "test2");
		jean.signForm(*rrf);
		jean.executeForm(*rrf);
		delete rrf;
		rrf = someRandomIntern.makeForm(form[0], "test3");
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