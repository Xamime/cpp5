/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 12:43:00 by maxime            #+#    #+#             */
/*   Updated: 2024/01/04 14:18:53 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T cont, int value)
{
    if (std::find(cont.begin(), cont.end(), value) == cont.end())
        throw std::exception();
}