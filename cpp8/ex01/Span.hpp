/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:32:49 by maxime            #+#    #+#             */
/*   Updated: 2024/01/17 13:32:31 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <ctime>
#include <algorithm>

class Span
{
    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int N);
        int     shortestSpan();
        int     longestSpan();
        void    fillSpan(unsigned int N);
        class TooMuchNumbers : public std::exception
        {
            public:
		        const char *what(void) const throw();        
        };
        class TooFewNumbers : public std::exception
        {
            public:
		        const char *what(void) const throw();        
        };
    private:
        std::vector<int> _array;
        unsigned long _numbers;
};

const char *Span::TooMuchNumbers::what(void) const throw()
{
    return ("You cannot add more numbers");
}

const char *Span::TooFewNumbers::what(void) const throw()
{
    return ("Not enough numbers stored");
}

Span::Span()
{
    _numbers = 0;
}

Span::Span(unsigned int N)
{
    _numbers = N;
}

Span::Span(const Span& other)
{
    (void)other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
    }
    return *this;
}

void    Span::fillSpan(unsigned int N)
{
    std::srand(int(std::time(NULL)));
    _array.resize(N);
    std::generate(_array.begin(), _array.end(), std::rand);
}

int    Span::shortestSpan()
{
    if (_array.size() < 2)
        throw Span::TooFewNumbers();
    std::sort(_array.begin(), _array.end());
    int comp = _array[1] - _array[0];
    for (int i = 0; i < (int)_numbers - 1; i++){
        if (comp > (_array[i + 1] - _array[i]))
            comp = _array[i + 1] - _array[i];
    }
    return (comp);
}

int    Span::longestSpan()
{
    if (_array.size() < 2)
        throw Span::TooFewNumbers();
    int min = *std::min_element(_array.begin(), _array.end());
    int max = *std::max_element(_array.begin(), _array.end());
    return (max - min);
}

void    Span::addNumber(int N)
{
    if (_array.size() >= _numbers)
        throw Span::TooMuchNumbers();
    _array.push_back(N);
}

Span::~Span() {
}