/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:28:26 by everonel          #+#    #+#             */
/*   Updated: 2023/11/19 16:04:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*__________________________________________
|________________Constructors_______________|
*/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) { 
    try {
        _validateGrade(grade);
        _grade = grade;
        std::cout << "\033[3;36mA new Bureaucrat has been allocated successfully! The name is : " << _name << TEXT_RESET << std::endl;
    }
    catch (GradeTooHighException& ex) {
        std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
    }
    catch (GradeTooLowException& ex) {
        std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

Bureaucrat::~Bureaucrat( ) { 
    std::cout << "\033[3;36mA Bureaucrat has been burried. rest in peace " << _name << TEXT_RESET << std::endl;
}

/*__________________________________________
|_____________Getters / Setters_____________|
*/
const std::string   &Bureaucrat::getName( ) const { return _name; }

int                 Bureaucrat::getGrade( ) const {  return _grade; }

/*__________________________________________
|_______________Public Methods______________|
*/
void    Bureaucrat::decrementGrade( ) {
    try{
		_validateGrade(_grade + 1);
		_grade++;
        std::cout << COLOR_MSG_TESTING << _name << " grade decremented to " << _grade << TEXT_RESET << std::endl;
	}
    catch (std::exception& ex) {
		std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
    }
}

void    Bureaucrat::incrementGrade() {
    try {
        _validateGrade(_grade - 1);
        _grade--;
        std::cout << COLOR_MSG_TESTING << _name << " grade incremented to " << _grade << TEXT_RESET << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
    }
}

/*__________________________________________
|_____________Operator Overloads____________|
*/
const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src) {
    _grade = src._grade;
    return *this;
}

/*__________________________________________
|_________________Exceptions________________|
*/

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name, const std::string& cons) : _msg(name + " grade is too high" + cons) { }
const char *Bureaucrat::GradeTooHighException::what() throw()  { return _msg.c_str(); }

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name, const std::string& cons) : _msg(name + " grade is too low" + cons) { }
const char *Bureaucrat::GradeTooLowException::what() throw() { return _msg.c_str(); }

/*__________________________________________
|______________Private Methods______________|
*/
void        Bureaucrat::_validateGrade(int grade) {
    if (grade < 1) {
        _grade = 1;
        throw GradeTooHighException(_name, ": The grade is by default set to 1");
    }
    else if (grade > 150) {
        _grade = 150;
        throw GradeTooLowException(_name, ": The grade is by default set to 150");
    }
}

/*__________________________________________
|_________Stream Operator Overloads_________|
*/
std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
    out << "Name: " << src.getName() << std::endl;
    out << "Grade: " << src.getGrade() << std::endl;
    return out;
}