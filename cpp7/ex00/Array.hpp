/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:58 by maxime            #+#    #+#             */
/*   Updated: 2023/12/19 17:08:34 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
void    swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T&    min(T& a, T& b)
{
    if (a < b)
        return (a);
    return (b);
}

template<typename T>
T&    max(T& a, T& b)
{
    if (a > b)
        return (a);
    return (b);
}
#endif