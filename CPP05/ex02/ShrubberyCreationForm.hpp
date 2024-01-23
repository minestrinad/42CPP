/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:38:02 by everonel          #+#    #+#             */
/*   Updated: 2024/01/21 23:52:43 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP


# include <iostream>
# include <stdexcept>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        const int       _gradeToSign = 145;
        const int       _gradeToExec = 137;
        std::string     _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ~ShrubberyCreationForm();

        void    execute();
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

        class InvalidTargetException : public std::invalid_argument {
            public:
                InvalidTargetException(const std::string& name)
                    : std::invalid_argument("No such file: " + name) {}
        };
};

#endif