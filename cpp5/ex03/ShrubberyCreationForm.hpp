/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:03:29 by maxime            #+#    #+#             */
/*   Updated: 2023/12/14 11:00:50 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE
#define TREE

#include "AForm.hpp"

class ShrubberyCreationForm : public virtual AForm
{
    public:
    
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

        ~ShrubberyCreationForm();

        void    execute(Bureaucrat const & executor) const;

    private:
        void        treestyle() const;
};

#endif