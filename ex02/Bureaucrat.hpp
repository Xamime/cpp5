
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 11:52:51 by maxime            #+#    #+#             */
/*   Updated: 2023/11/26 12:56:53 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:

        Bureaucrat();
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & ref);
        ~Bureaucrat();
        Bureaucrat & operator=(Bureaucrat const & ref);

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

        void                setGrade(int grade);
        const std::string   getName() const;
        int                 getGrade() const;
        void                GradeUp();
        void                GradeDown();

        void                signForm(AForm & src);
        void                executeForm(AForm const & form);

    private:

        int               _grade;
        const std::string _name;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & ref);

#endif