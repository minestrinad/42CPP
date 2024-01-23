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

#include "AForm.hpp"

/*__________________________________________
|________________Constructors_______________|
*/
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _isSigned(false) {
    try {
        _validateGrade(gradeToSign);
        _validateGrade(gradeToExecute);
        std::cout << MSG_CONSTRUCTION << _name << TEXT_RESET << std::endl;
    }
    catch (std::exception& ex) {
        handleException(ex);
    }
}

AForm::AForm(const AForm& src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _isSigned(false) { }

AForm::~AForm() {
    std::cout << MSG_DESTRUCTION << _name << TEXT_RESET << std::endl;
}

/*__________________________________________
|_____________Getters / Setters_____________|
*/
const std::string& AForm::getName() const { return _name; }

const int          &AForm::getGradeToSign() const { return _gradeToSign; }

const int          &AForm::getGradeToExecute() const { return _gradeToSign; }

bool               AForm::getIsSigned() const { return _isSigned; }

/*__________________________________________
|_______________Public Methods______________|
*/

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    
    if (_gradeToSign < 1) {
        throw AForm::GradeTooHighException(_name, ": The AForm grade is invalid");
    }
    else if (_gradeToSign > 150) {
        throw AForm::GradeTooLowException(_name, ": The AForm grade is invalid");
    }
    else if (bureaucrat.getGrade() > _gradeToSign) {
		throw Bureaucrat::GradeTooLowException(_name, ": The grade is too low to sign this Aform");
    }
    else if (_isSigned) {
        throw AForm::AlreadySignedException(_name, "");
	}
    else {
		_isSigned = true;
		std::cout << COLOR_MSG_TESTING << bureaucrat.getName() << " signed " << _name << TEXT_RESET << std::endl;
	}
}

void    AForm::handleException(const std::exception& ex) {
    std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
}

/*__________________________________________
|_____________Operator Overloads____________|
*/
const AForm& AForm::operator=(const AForm& src) {
    if (this == &src)
		return *this;
    _isSigned = src._isSigned;
    return *this;
}

/*__________________________________________
|______________Private Methods______________|
*/
void        AForm::_validateGrade(int grade) {
    if (grade < 1) {
        throw AForm::GradeTooHighException(_name, ": The AForm is invalid");
    }
    else if (grade > 150) {
        throw AForm::GradeTooLowException(_name, ": The AForm is invalid");
    }
}

/*__________________________________________
|_________Stream Operator Overloads_________|
*/
std::ostream& operator<<(std::ostream& out, const AForm& src) {
    out << "Name: " << src.getName() << std::endl;
    out << "Grade To Sign: " << src.getGradeToSign() << std::endl;
    out << "Grade To Execute: " << src.getGradeToExecute() << std::endl;
    out << "Is Signed: ";
    src.getIsSigned() ? out << "Yes" : out << "No";
    out << std::endl;
    return out;
}