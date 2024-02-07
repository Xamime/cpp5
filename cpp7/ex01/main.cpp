/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:47:08 by maxime            #+#    #+#             */
/*   Updated: 2024/02/05 16:24:33 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main()
{
    int array[5] = {1,2,3,4,5};
    int len = 5;
    char str[6] = "abcde";
    iter(array, len, print<int>);
    iter(str, len, print<char>);

} 