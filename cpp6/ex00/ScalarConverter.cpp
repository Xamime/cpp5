/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:55:48 by maxime            #+#    #+#             */
/*   Updated: 2024/02/01 16:24:27 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::e_type ScalarConverter::_type = ScalarConverter::Null;
char                    ScalarConverter::_c = 0;
float                   ScalarConverter::_f = 0.0f;
double                  ScalarConverter::_d = 0.0;
int                     ScalarConverter::_i = 0;
long long               ScalarConverter::_ll = 0;

const char *ScalarConverter::CannotConvert::what(void) const throw()
{
    return ("Error\nCannot convert this");
}

void    ScalarConverter::print()
{
    if (_type == Nan || _type == Inf || _i < 0 || _i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (isprint(_c))
        std::cout << "char: " << _c << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    if (_type == Nan || _type == Inf || _ll < -2147483648 || _ll > 2147483647)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << _i << std::endl;
    std::cout << "float: " << _f;
    if (static_cast<float>(_i) == _f)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << _d;
    if (static_cast<double>(_i) == _d)
        std::cout << ".0";
    std::cout << std::endl;
}

ScalarConverter::e_type	ScalarConverter::DetermineType(std::string input)
{
	size_t	max;
	bool	isDouble	= false;
    
	if (input.length() == 1 && !std::isdigit(input[0]))
		return (Char);
	if (input == "nan" || input == "nanf")
		return (Nan);
	if (input[0] == '-' || input[0] == '+')
		input = input.substr(1);
    max	= input.length();
	if (input == "inf" || input == "inff")
		return (Inf);
	for (size_t i = 0; i < max; i++)
	{
		if (isDouble && i == max-1 && (input[i] == 'f' || input[i] == 'F'))
			return (Float);
		if (input[i] == '.')
		{
			if (isDouble)
				return (Null);
			isDouble = true;
			continue ;
		}
		if (!std::isdigit(input[i]))
			return (Null);
	}
	if (isDouble)
		return (Double);
	else
		return (Int);
}

void ScalarConverter::convert(std::string str)
{
    _type = DetermineType(str);
    if (_type == Null)
        throw ScalarConverter::CannotConvert();
    if (_type == Char){
       _c = str[0];
       _f = static_cast<float>(_c);
       _d = static_cast<double>(_c);
       _i = static_cast<int>(_c);
    }
    else if (_type == Int){
        _ll = atoll(str.c_str());
        _i = atoi(str.c_str());
        _f = static_cast<float>(_i);
        _d = static_cast<double>(_i);
        _c = static_cast<char>(_i);
    }
    else if (_type == Float){
        _ll = atoll(str.c_str());
        _f = strtof(str.c_str(), NULL);
        _i = static_cast<int>(_f);
        _d = static_cast<double>(_f);
        _c = static_cast<char>(_f);
    }
    else if (_type == Double || _type == Inf || _type == Nan){
        _ll = atoll(str.c_str());
        _d = strtod(str.c_str(), NULL);
        _i = static_cast<int>(_d);
        _f = static_cast<float>(_d);
        _c = static_cast<char>(_d);       
    }
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    if (this != &other)
    {
    }
    return *this;
}

ScalarConverter::~ScalarConverter() {
}