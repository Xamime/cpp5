/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:45:17 by maxime            #+#    #+#             */
/*   Updated: 2024/01/30 16:42:45 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONV_HPP
#define SCALARCONV_HPP

#include <iostream>
#include <limits>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);

        virtual ~ScalarConverter() = 0;
        
        enum e_type { Null, Char, Int, Float, Double, Nan, Inf};
        static void convert(std::string str);
        static void print();
        static e_type DetermineType(std::string input);
        
        class CannotConvert : public std::exception
        {
	        public:
		        const char *what(void) const throw();
	    };

    private:

        static e_type   _type;
        static char     _c;
        static float    _f;
        static double   _d;
        static int      _i;
};



#endif