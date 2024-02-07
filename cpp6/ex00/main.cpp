/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:53 by maxime            #+#    #+#             */
/*   Updated: 2024/02/01 16:18:42 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2){
        std::cout << "need 1 argument\n";
        return (1);
    }

    std::string str(argv[1]);
    try {
        ScalarConverter::convert(str);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
        return (1);
    }
    ScalarConverter::print();
    return (0);
}