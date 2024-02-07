/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:54 by mdesrose          #+#    #+#             */
/*   Updated: 2024/02/07 17:56:42 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <fstream>
#include <iostream>
#include <regex.h>
#include <algorithm>

// void    check_date_format(std::string str)
// {
//     std::regex reg();
//         std::cout << str << ": " << std::boolalpha
//                   << std::regex_search(str, reg) << '\n';
//     std::cout << '\n';
// }

int regexCompare(std::string str, std::string scalarPattern)
{
    regex_t toConvert;

    if (regcomp(&toConvert, scalarPattern.c_str(), REG_EXTENDED) != 0)
        return (0);
    if (regexec(&toConvert, str.c_str(), 0, NULL, 0) == REG_NOMATCH)
    {
        regfree(&toConvert);
        return (0);
    }
    regfree(&toConvert);
    return (1);
}

void    split_and_insert(std::string str, std::map<std::string, double>& map)
{
    size_t pos = str.find(" | ");
    if (pos != std::string::npos)
    {
            std::string key = str.substr(0, pos);
            std::string valueStr = str.substr(pos + 1);
            double value = atof(valueStr.c_str());
            map[key] = value;
    }
}

int main(int argc, char *argv[])
{
    std::map<std::string, double>   m;
    std::string                     line;
    std::ifstream	                infile(argv[1], std::ios::in);
    std::string                     str = "(^((([0-9][0-9])(([02468][048])|([13579][26]))-02-29)|((([0-9][0-9])([0-9][0-9])))-((((0[0-9])|(1[0-2]))-((0[0-9])|(1[0-9])|(2[0-8])))|((((0[13578])|(1[02]))-31)|(((0[1,3-9])|(1[0-2]))-(29|30))))) | (([0-9]{1,})|(([0-9]{1,}).([0-9]{1,})))$)";
    int i = 0;
    if (argc != 2){
        std::cerr << "need a file\n";
        return (1);
    }
	if (!infile)
	{
		std::cerr << "Can't open " << argv[1] << std::endl;
		return (1);
	}
    try
    {
        while (getline(infile, line))
	    {
            if (regexCompare(line, str.c_str()))
            {
                split_and_insert(line, m);
            }
            else if (i == 0 && line != "date | value")
            {
                throw std::exception();
            }
            else if (i != 0)
                std::cout << "Error: bad input => " << line << std::endl;
            i++;
	    }
    }
    catch(const std::exception& e)
    {
        std::cerr << "Bad Format" << '\n';
    }
    infile.close();
    return 0;
}
