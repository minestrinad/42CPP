/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:08:10 by everonel          #+#    #+#             */
/*   Updated: 2024/01/30 15:11:47 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm( std::string );
        PresidentialPardonForm( const PresidentialPardonForm & );
        ~PresidentialPardonForm( );

        void    action( ) const;
        std::string getTarget() const { return _target; };

        PresidentialPardonForm &operator=( const PresidentialPardonForm & );
};

#endif