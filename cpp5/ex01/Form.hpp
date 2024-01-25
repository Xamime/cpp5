/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesrose <mdesrose@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:59:43 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 15:56:57 by mdesrose         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(std::string name, int sign_grade, int exec_grade);
        Form(const Form& other);
        Form& operator=(const Form& other);

        ~Form();

        std::string getName() const;
        bool        getSign() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        void        beSigned(Bureaucrat & src);

    class GradeTooHighException : public std::exception
        {
	        public:
		        const char *what(void) const throw();
	    };

	    class GradeTooLowException : public std::exception
        {
        	public:
	          	const char *what(void) const throw();
	    };
        
        class AlreadySign : public std::exception
        {
        	public:
	          	const char *what(void) const throw();
	    };

    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;
};

std::ostream & operator<<(std::ostream & o, Form & ref);

#endif