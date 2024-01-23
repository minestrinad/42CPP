/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 17:14:29 by everonel          #+#    #+#             */
/*   Updated: 2024/01/23 17:20:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialParonForm", 25, 5), _target(target) { }

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) { *this = src; }

PresidentialPardonForm::~PresidentialPardonForm( ) { }

void    PresidentialPardonForm::execute( ) 
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &src )
{
    if ( this == &src )
        return *this;
    _target = src._target;
    return *this;
}

