/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:28:26 by everonel          #+#    #+#             */
/*   Updated: 2023/11/19 16:04:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*__________________________________________
|________________Constructors_______________|
*/
Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
    try {
        _validateGrade(gradeToSign);
        _validateGrade(gradeToExecute);
        std::cout << MSG_CONSTRUCTION << _name << TEXT_RESET << std::endl;
    }
    catch (std::exception& ex) {
        handleException(ex);
        delete this;
    }
}

Form::Form(const Form& src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(false) { }

Form::~Form() {
    std::cout << MSG_DESTRUCTION << _name << TEXT_RESET << std::endl;
}

/*__________________________________________
|_____________Getters / Setters_____________|
*/
const std::string& Form::getName() const { return _name; }

const int          Form::getGradeToSign() const { return _gradeToSign; }

const int          Form::getGradeToExecute() const { return _gradeToSign; }

bool               Form::getIsSigned() const { return _isSigned; }

/*__________________________________________
|_______________Public Methods______________|
*/

void    Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
		throw Bureaucrat::GradeTooLowException(_name, ": The grade is too low to sign this form");
    }
    else if (_isSigned) {
        throw Form::AlreadySignedException(_name, "");
	}
    else {
		_isSigned = true;
		std::cout << COLOR_MSG_TESTING << bureaucrat.getName() << " signed " << _name << TEXT_RESET << std::endl;
	}
}

void    Form::handleException(const std::exception& ex) {
    std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
}

/*__________________________________________
|_____________Operator Overloads____________|
*/
const Form& Form::operator=(const Form& src) {
    if (this == &src)
		return *this;
    _isSigned = src._isSigned;
    return *this;
}

/*__________________________________________
|______________Private Methods______________|
*/
void        Form::_validateGrade(int grade) {
    if (grade < 1) {
        throw Form::GradeTooHighException(_name, ": The grade is by default set to 1");
    }
    else if (grade > 150) {
        throw Form::GradeTooLowException(_name, ": The grade is by default set to 150");
    }
}

/*__________________________________________
|_________Stream Operator Overloads_________|
*/
std::ostream& operator<<(std::ostream& out, const Form& src) {
    out << "Name: " << src.getName() << std::endl;
    out << "Grade To Sign: " << src.getGradeToSign() << std::endl;
    out << "Grade To Execute: " << src.getGradeToExecute() << std::endl;
    out << "Is Signed: ";
    src.getIsSigned() ? out << "Yes" : out << "No";
    out << std::endl;
    return out;
}