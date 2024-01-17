/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:18:31 by maxime            #+#    #+#             */
/*   Updated: 2023/12/18 16:59:45 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data test;
    Data *test2;
    uintptr_t ptr;
    ptr = Serializer::serialize(&test);
    test2 = Serializer::deserialize(ptr);
    if (&test == test2)
        std::cout << "Success" << std::endl;
    else   
        std::cout << "Nope" << std::endl;
}