/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:44:15 by everonel          #+#    #+#             */
/*   Updated: 2023/10/01 11:14:16 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

//      You have to create a Harl class with the following private member functions:
//          •void debug( void );
//          •void info( void );
//          •void warning( void );
//          •void error( void );
# include <iostream>

class Harl
{
    public:
        Harl( void );
        ~Harl( void );
        void complain( std::string level );
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    private:
};

#endif
