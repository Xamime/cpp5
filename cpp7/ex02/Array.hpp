/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:11:27 by maxime            #+#    #+#             */
/*   Updated: 2024/02/05 16:39:37 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class Array
{
    public:
    
        Array() : elements(NULL), _s(0)
        {
        }
        
        Array(unsigned int n)
        {
            elements = new T[n]; 
            _s = n;
                for (size_t i = 0; i < _s; i++){
                    elements[i] = T();
                }
        }

        Array(const Array& other)
        {
            _s = other.size();
            elements = new T[_s];
            for (size_t i = 0; i < _s;i++)
            {
                elements[i] = other.elements[i];
            }
        }
        
        Array& operator=(const Array& other)
        {
            if (this != &other && elements == NULL)
            {
                _s = other.size();
                elements = new T[_s];
                for (size_t i = 0; i < _s;i++)
                {
                    elements[i] = other.elements[i];
                }
            }
            return (*this);
        }

        T& operator[](unsigned int n)
        {
            if (n >= _s)
                throw std::exception();
            return (elements[n]);
        }
        
        void addElement(const T& element)
        {
            T* newElements = new T[_s + 1];
            for (std::size_t i = 0; i < _s; ++i) {
                newElements[i] = elements[i];
            }
            newElements[_s] = element;
            delete[] elements;
            elements = newElements;
            ++_s;
        }

        std::size_t size() const {
            return _s;
        }
        
        ~Array(){
            delete[] elements;
        }

        void    printarray()
        {
            for (size_t i = 0; i< _s;i++)
            {
                std::cout << elements[i] << std::endl;
            }
        }

    private:
        T *elements;
        size_t _s;
};

#endif