/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:03:58 by maxime            #+#    #+#             */
/*   Updated: 2024/01/03 15:15:18 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"



int main()
{
    try
    {
        std::cout << "INT ARRAY TEST\n";
        Array<int> test(5);
        test.addElement(32);
        Array<int> test2(test);
        test[2] = 42;
        Array<int> assign;
        assign = test;
        assign = test2;
        std::cout << "assignement test !!" << std::endl;
        assign.printarray();
        
        std::cout << "test1 test !!" << std::endl;
        test.printarray();
        
        std::cout << "test2 test !!" << std::endl;
        test2.printarray();
        
        std::cout << "String ARRAY TEST\n";
        Array<std::string> str(2);
        str[0] = "alooo";
        str.addElement("does it work ?");
        str.printarray();
        
        std::cout << "index test !!" << std::endl;
        std::cout << test[2] << std::endl;
        std::cout << test[5] << std::endl;
        std::cout << test[8] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "index out of bounds\n";
    }
    
}