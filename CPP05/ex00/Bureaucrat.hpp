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

// colors and fonts:
# define TEXT_RESET "\033[0m"
# define COLOR_MSG_CONSTRUCTION "\033[1;36m"
# define COLOR_MSG_EXCEPTIONS "\033[1;31m"
// text italic cyan:
# define TEXT_ICYAN "\033[3;36m"
// text bold red:
# define TEXT_BRED "\033[1;31m"
// text italic yellow:
# define COLOR_MSG_TESTING "\033[3;33m"

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
    public:
        /*__________________________________________
        |________________Constructors_______________|
        */ 
        Bureaucrat( std::string, int );
        Bureaucrat( const Bureaucrat & );
        ~Bureaucrat( );

        /*__________________________________________
        |_____________Getters / Setters_____________|
        */
        const std::string   &getName( ) const;
        int                 getGrade( ) const;
        
        /*__________________________________________
        |_______________Public Methods______________|
        */
        void        incrementGrade( );
        void        decrementGrade( );
        // void        handleException(const std::exception& ex);
        /*__________________________________________
        |_____________Operator Overloads____________|
        */
        const Bureaucrat &operator=(const Bureaucrat &);

        /*__________________________________________
        |_________________Exceptions________________|
        */
        class GradeTooHighException : public std::exception
        {
            public:
                GradeTooHighException(const std::string& name, const std::string& cons);
                ~GradeTooHighException() throw() { };
                virtual const char* what() throw();
            private:
                std::string _msg;
        };

        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException(const std::string& name, const std::string& cons);
                ~GradeTooLowException() throw() { };
                virtual const char* what() throw();
            private:
                std::string _msg;
        };

    private:
        /*__________________________________________
        |_________________Attributes________________|
        */
        const std::string   _name;
        int                 _grade;
        
        /*__________________________________________
        |______________Private Methods______________|
        */
        void        _validateGrade(int);
};

/*__________________________________________
|_________Stream Operator Overloads_________|
*/
std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif

