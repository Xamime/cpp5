/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:54 by mdesrose          #+#    #+#             */
/*   Updated: 2024/01/29 15:25:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <fstream>
#include <iostream>

void    check_date_format(std::string str)
{
    if (str[4] != '-' || str[7] != '-')
    {
        std::cout << "Bad format." << std::endl;
        throw std::exception();
    }
    
}

int main(int argc, char *argv[])
{
    std::map<std::string, double>   m;
    std::string                     line;
    std::ifstream	                infile(argv[1], std::ios::in);

    if (argc != 2){
        std::cout << "need a file\n";
        return (1);
    }
	if (!infile)
	{
		std::cerr << "Can't open " << argv[1] << std::endl;
		return 1;
	}
    try
    {
        int i = 0;
        while (getline(infile, line))
	    {
            if (i == 0 && line != "date | value")
            {
                std::cout << "Bad format" << std::endl;
                throw std::exception();
            }
            else if (i == 0)
            {
                i++;
                continue;
            }
            check_date_format(line);
            i++;
	    }
    }
    catch(const std::exception& e)
    {
    }
    infile.close();
    return 0;
}
