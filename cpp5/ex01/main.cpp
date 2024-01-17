/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2023/12/12 14:45:33 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Form un("B328", 9, 10);
    Bureaucrat jean("grade1", 1);
    Bureaucrat toto("grade50", 50);
    Bureaucrat boulard("grade150", 150);
    try
    {
        jean.GradeUp();
        jean.GradeDown();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    jean.signForm(un);
    toto.signForm(un);
    boulard.signForm(un);
    
    std::cout << jean << std::endl;
    std::cout << un << std::endl;
}