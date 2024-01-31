/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:59:12 by maxime            #+#    #+#             */
/*   Updated: 2024/01/30 15:41:03 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _serializer_
#define _serializer_

#include <iostream>
#include <stdint.h>

typedef struct s_data
{
    int a;
}               Data;

class Serializer
{
    public:
        Serializer();
        Serializer(const Serializer& other);
        Serializer& operator=(const Serializer& other);

        virtual ~Serializer() = 0;

        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
    private:
};

#endif
