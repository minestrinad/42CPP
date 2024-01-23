/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 01:38:02 by everonel          #+#    #+#             */
/*   Updated: 2024/01/23 16:58:42 by everonel         ###   ########.fr       */
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

        void    execute();
        
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);
};

#endif