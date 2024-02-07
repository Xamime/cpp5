/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:48:14 by maxime            #+#    #+#             */
/*   Updated: 2024/02/05 16:24:14 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename Func>
void    iter(T* adress, int len, Func func)
{
    for (int i = 0; i < len;i++){
        func(adress[i]);
    }
}

template<typename T>
void    print(T& arg)
{
    std::cout << "Element : " << arg << std::endl;
}


#endif