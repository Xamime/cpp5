/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:18:31 by maxime            #+#    #+#             */
/*   Updated: 2024/01/30 15:40:15 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data test;
    Data *test2;
    uintptr_t ptr;
    test.a = 142;
    ptr = Serializer::serialize(&test);
    test2 = Serializer::deserialize(ptr);
    if (&test == test2)
        std::cout << "Success" << std::endl;
    else   
        std::cout << "Nope" << std::endl;
    std::cout << test2->a << std::endl;
}