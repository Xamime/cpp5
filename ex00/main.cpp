/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 12:39:33 by maxime            #+#    #+#             */
/*   Updated: 2023/12/11 06:14:33 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat jean("jeanne", 10);
    Bureaucrat jean1("tester", 2);
    try
    {
        jean.setGrade(100);
        while(1)
        {
            //jean.GradeDown();
            jean1.GradeUp();
        }
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    Bureaucrat yo;
    yo = jean1;
    Bureaucrat yop(jean1);

    std::cout << yo << std::endl;
    std::cout << "ici   ";
    std::cout << yop <<  std::endl;
    std::cout << jean1 << std::endl;
    std::cout << jean << std::endl;
}