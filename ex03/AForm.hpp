/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 19:59:43 by maxime            #+#    #+#             */
/*   Updated: 2023/11/27 20:52:56 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm();
        AForm(std::string name, std::string target, int sign_grade, int exec_grade);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        virtual ~AForm();

        std::string     getTarget() const;
        std::string     getName() const;
        void            setSign(bool sign);
        bool            getSign() const;
        int             getSignGrade() const;
        int             getExecGrade() const;

        void            beSigned(Bureaucrat & src);
        virtual void    execute(Bureaucrat const & executor) const = 0;

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

        class IsnotSigned : public std::exception
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
        std::string         _target;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;

};

std::ostream & operator<<(std::ostream & o, AForm & ref);

#endif