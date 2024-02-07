/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Swap.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:25:58 by maxime            #+#    #+#             */
/*   Updated: 2024/02/05 16:08:50 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
#define SWAP_H

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