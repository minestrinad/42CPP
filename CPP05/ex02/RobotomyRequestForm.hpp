/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:47:59 by everonel          #+#    #+#             */
/*   Updated: 2024/01/23 17:18:42 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm( std::string );
        RobotomyRequestForm( const RobotomyRequestForm & );
        ~RobotomyRequestForm( );

        void    execute( );

        RobotomyRequestForm &operator=( const RobotomyRequestForm & );
};

#endif

