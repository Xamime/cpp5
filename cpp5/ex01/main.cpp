/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 16:11:58 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Form un("B328", 9, 10);
    Form deux(un);
    Bureaucrat jean("grade1", 1);
    Bureaucrat toto("grade50", 50);
    Bureaucrat boulard("grade150", 150);
    Bureaucrat jeanine(jean);
    try
    {
        jean.GradeUp();
        //jean.GradeDown();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "\nsign form 1\n\n";
    
    boulard.signForm(un);
    jean.signForm(un);
    toto.signForm(un);

    std::cout << "\nsign form 2\n\n";
    
    boulard.signForm(deux);
    jean.signForm(deux);
    toto.signForm(deux);

    std::cout << "\ntest operator<<\n\n";

    std::cout << jeanine << std::endl << std::endl;
    std::cout << jean << std::endl << std::endl;
    std::cout << un << std::endl << std::endl;
}