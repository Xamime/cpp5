/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxime <maxime@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:04:14 by maxime            #+#    #+#             */
/*   Updated: 2023/12/11 16:27:36 by maxime           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ROBO_
#define _ROBO_

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public virtual AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

        ~RobotomyRequestForm();

        virtual void    execute(Bureaucrat const & executor) const;

    private:
        void    robotomy() const;
};
#endif