/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:38:57 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 11:14:13 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( ) { 
    _registry["ShrubberyCreationForm"] = &Intern::_createShrubberyCreationForm;
    _registry["RobotomyRequestForm"] = &Intern::_createRobotomyRequestForm;
    _registry["PresidentialPardonForm"] = &Intern::_createPresidentialPardonForm;

}

Intern::Intern(Intern const &src) {  *this = src; }

Intern::~Intern( ) { }

AForm   *Intern::makeForm( const std::string &name, const std::string &target ) {
    std::map<std::string, FormCreationFunction>::iterator form = _registry.find(name);
    if ( form != _registry.end()) {
        Intern *internInstance = this;
        return (internInstance->*(form->second))(target);
    }
    throw Intern::InvalidFormException(name);
}

Intern  &Intern::operator=( const Intern &src ) {
    _registry = src._registry;
    return *this;
}

Intern::InvalidFormException::InvalidFormException( const std::string &name ) : std::invalid_argument(name + " is not a valid Form" ) { }

AForm *Intern::_createShrubberyCreationForm( const std::string &target ) { return new ShrubberyCreationForm(target); }

AForm *Intern::_createRobotomyRequestForm( const std::string &target ) { return new RobotomyRequestForm(target); }

AForm *Intern::_createPresidentialPardonForm( const std::string &target ) { return new PresidentialPardonForm(target); }





