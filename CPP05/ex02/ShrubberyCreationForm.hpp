/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:38:02 by everonel          #+#    #+#             */
/*   Updated: 2024/01/27 21:23:25 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string     _target;

    public:
        ShrubberyCreationForm( );
        ShrubberyCreationForm( std::string target );
        ShrubberyCreationForm(const ShrubberyCreationForm &);
        ~ShrubberyCreationForm( );

        void    action() const;
        
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
};

#endif