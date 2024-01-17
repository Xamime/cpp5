/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:59:12 by maxime            #+#    #+#             */
/*   Updated: 2023/12/18 16:40:27 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
