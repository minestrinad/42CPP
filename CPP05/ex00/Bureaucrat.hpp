/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:27:15 by everonel          #+#    #+#             */
/*   Updated: 2023/11/19 15:42:53 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREUCRAT_HPP

# define COLOR_RESET "\033[0m"
# define COLOR_DEBUG "\033[1;32m"
# define COLOR_ERROR "\033[1;31m"

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat( std::string, int );
        Bureaucrat( const Bureaucrat & );
        ~Bureaucrat( );

        std::string getName( ) const;
        int         getGrade( ) const;
        
        void        incrementGrade( );
        void        decrementGrade( );
        
        const Bureaucrat &operator=(const Bureaucrat &);
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char		*what() const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char		*what() const throw();
        };
    private:
        std::string _name;
        int         _grade;
};

#endif