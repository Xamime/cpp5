/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:39:50 by maxime            #+#    #+#             */
/*   Updated: 2024/01/17 14:55:39 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <iostream>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
    
        ~MutantStack();
        
        MutantStack<T>::iterator   begin();
        MutantStack<T>::iterator   end();
        class iterator : public std::iterator<T>
        {
        };
    private:

};

template<typename T>
MutantStack<T>::iterator   begin()
{
    
}

template<class T>
MutantStack<T>::MutantStack()
{
}

template<class T>
MutantStack<T>::MutantStack(const MutantStack& other)
{
    (void)other;
}

template<class T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& other)
{
    if (this != &other)
    {
    }
    return *this;
}

template<class T>
MutantStack<T>::~MutantStack() {
}

#endif