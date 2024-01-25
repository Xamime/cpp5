/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:54 by mdesrose          #+#    #+#             */
/*   Updated: 2024/01/25 16:14:14 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <fstream>
#include <iostream>

void    check_date_format(std::string str)
{
    if (str[])
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
        while (getline(infile, line))
	    {
		    std::cout << line << std::endl;
	    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
    infile.close();
    return 0;
}
