/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:14:29 by everonel          #+#    #+#             */
/*   Updated: 2024/01/27 21:23:47 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialParonForm", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) : AForm(src), _target(src._target) { }

PresidentialPardonForm::~PresidentialPardonForm( ) { }

void    PresidentialPardonForm::action( )const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
    if ( this == &src )
        return *this;
    _target = src._target;
    return *this;
}

