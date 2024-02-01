/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 21:31:49 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 11:11:49 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#ifndef INTER_HPP
# define INTER_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <map>

class Intern 
{
    public:
        Intern( );
        Intern( const Intern & );
        ~Intern( );

        AForm *makeForm( const std::string &, const std::string &);

        Intern &operator=( const Intern & );
        
        class InvalidFormException : public std::invalid_argument {
            public:
                InvalidFormException( const std::string &);
        };
    private:
        typedef AForm* (Intern::*FormCreationFunction)(const std::string &);
        
        std::map<std::string, FormCreationFunction> _registry;
        
        AForm* _createShrubberyCreationForm(const std::string &);
        AForm* _createRobotomyRequestForm(const std::string &);
        AForm* _createPresidentialPardonForm(const std::string &);
};

#endif