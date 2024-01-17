/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:11:27 by maxime            #+#    #+#             */
/*   Updated: 2024/01/03 15:17:18 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template<class T>
class Array
{
    public:
    
        Array() : elements(NULL), size(0)
        {
        }
        
        Array(unsigned int n)
        {
            elements = new T[n]; 
            size = n;
                for (size_t i = 0; i < size; i++){
                    elements[i] = T();
                }
        }

        Array(const Array& other)
        {
            size = other.getSize();
            elements = new T[size];
            for (size_t i = 0; i < size;i++)
            {
                elements[i] = other.elements[i];
            }
        }
        
        Array& operator=(const Array& other)
        {
            if (this != &other && elements == NULL)
            {
                size = other.getSize();
                elements = new T[size];
                for (size_t i = 0; i < size;i++)
                {
                    elements[i] = other.elements[i];
                }
            }
            return (*this);
        }

        T& operator[](unsigned int n)
        {
            if (n >= size)
                throw std::exception();
            return (elements[n]);
        }
        
        void addElement(const T& element)
        {
            T* newElements = new T[size + 1];
            for (std::size_t i = 0; i < size; ++i) {
                newElements[i] = elements[i];
            }
            newElements[size] = element;
            delete[] elements;
            elements = newElements;
            ++size;
        }

        std::size_t getSize() const {
            return size;
        }
        
        ~Array(){
            delete[] elements;
        }

        void    printarray()
        {
            for (size_t i = 0; i< size;i++)
            {
                std::cout << elements[i] << std::endl;
            }
        }

    private:
        T *elements;
        size_t size;
};

#endif