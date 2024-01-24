/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:03:29 by maxime            #+#    #+#             */
/*   Updated: 2024/01/24 10:37:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TREE_
#define _TREE_

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