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

#pragma once
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
        virtual ~AForm() = 0;

        /*__________________________________________
        |_____________Getters / Setters_____________|
        */
        const std::string       &getName() const;
        const int               &getGradeToSign() const;
        const int               &getGradeToExecute() const;
        bool                    getIsSigned() const;
        virtual std::string     getTarget() const = 0;

        /*__________________________________________
        |_______________Public Methods______________|
        */
        void            beSigned(const Bureaucrat&);
        void            execute(Bureaucrat const & executor);
        virtual void    action() const = 0;
        void            handleException(const std::exception& ex);
        /*__________________________________________
        |_____________Operator Overloads____________|
        */
        const   AForm& operator=(const AForm&);
        // virtual std::ostream& print(std::ostream &os) const {
        //     std::cout << "TEST" << std::endl;
        //     return os;
        // };

        /*__________________________________________
        |_________________Exceptions________________|
        */
        class GradeTooHighException : public std::invalid_argument
        {
            public:
                GradeTooHighException(const std::string &name, const std::string &cons);
        };

        class GradeTooLowException : public std::invalid_argument
        {
            public:
                GradeTooLowException(const std::string &name, const std::string &cons);
        };

        class AlreadySignedException : public std::invalid_argument
        {
            public:
                AlreadySignedException(const std::string &name, const std::string &cons);
        };

        class TryingToExecNonSignedForm : public std::invalid_argument
        {
            public:
                TryingToExecNonSignedForm(const std::string &name, const std::string &extra);
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
        void        _validateForExecution(Bureaucrat const & executor);
};

/*__________________________________________
|_________Stream Operator Overloads_________|
*/
std::ostream& operator<<(std::ostream &, const AForm &);
// std::ostream& operator<<(std::ostream& os, const AForm& src);
#endif

