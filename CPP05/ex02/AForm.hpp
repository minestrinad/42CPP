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

#ifndef AFORM_HPP
# define AFORM_HPP

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

// messages:
# define MSG_CONSTRUCTION "\033[3;36mA new Form has been allocated successfully! The name is : "
# define MSG_DESTRUCTION "\033[3;36mA Form has been burried. rest in peace "

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        /*__________________________________________
        |________________Constructors_______________|
        */
        AForm(std::string, int, int);
        AForm(const AForm&);
        ~AForm();

        /*__________________________________________
        |_____________Getters / Setters_____________|
        */
        const std::string       &getName() const;
        const int               &getGradeToSign() const;
        const int               &getGradeToExecute() const;
        bool                    getIsSigned() const;

        /*__________________________________________
        |_______________Public Methods______________|
        */
        void        beSigned(const Bureaucrat&);
        void        handleException(const std::exception& ex);
        /*__________________________________________
        |_____________Operator Overloads____________|
        */
        const AForm& operator=(const AForm&);

        /*__________________________________________
        |_________________Exceptions________________|
        */
        class GradeTooHighException : public std::invalid_argument
        {
            public:
                explicit GradeTooHighException(const std::string& name, const std::string& cons)
                    : std::invalid_argument(name + " grade is too high" + cons) {}
        };

        class GradeTooLowException : public std::invalid_argument
        {
            public:
                explicit GradeTooLowException(const std::string& name, const std::string& cons)
                    : std::invalid_argument(name + " grade is too low" + cons) {}
        };

        class AlreadySignedException : public std::invalid_argument
        {
            public:
                explicit AlreadySignedException(const std::string& name, const std::string& cons)
                    : std::invalid_argument(name + " is already signed" + cons) {}
        };

    private:
        /*__________________________________________
        |_________________Attributes________________|
        */
        const std::string   _name;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        bool                _isSigned;

        /*__________________________________________
        |______________Private Methods______________|
        */
        void        _validateGrade(int);
};

/*__________________________________________
|_________Stream Operator Overloads_________|
*/
std::ostream& operator<<(std::ostream&, const AForm&);
#endif

