/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:35:15 by maxime            #+#    #+#             */
/*   Updated: 2023/12/18 16:43:02 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t test = reinterpret_cast<uintptr_t>(ptr);
    return (test);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *test = reinterpret_cast<Data*>(raw);
    return (test);
}

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

Serializer& Serializer::operator=(const Serializer& other)
{
    if (this != &other)
    {
    }
    return *this;
}

Serializer::~Serializer() {
}
