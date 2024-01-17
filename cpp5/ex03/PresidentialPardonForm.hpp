/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:04:42 by maxime            #+#    #+#             */
/*   Updated: 2023/12/14 11:01:17 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARDON
#define PARDON

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

        ~PresidentialPardonForm();

        virtual void    execute(Bureaucrat const & executor) const;

    private:
};

#endif