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

const int          &AForm::getGradeToExecute() const { return _gradeToExecute; }

bool               AForm::getIsSigned() const { return _isSigned; }

/*__________________________________________
|_______________Public Methods______________|
*/

void    AForm::beSigned(const Bureaucrat& bureaucrat) {
    
    _validateGrade(_gradeToSign);
    if (bureaucrat.getGrade() > _gradeToSign) {
		throw Bureaucrat::GradeTooLowException(_name, ": The grade is too low to sign this form");
    }
    else if (_isSigned) {
        throw AForm::AlreadySignedException(_name, "");
	}
    else {
		_isSigned = true;
		std::cout << COLOR_MSG_TESTING << bureaucrat.getName() << " signed " << _name << TEXT_RESET << std::endl;
	}
}

void    AForm::execute(Bureaucrat const & executor) {
    if (!_isSigned) {
        throw AForm::TryingToExecNonSignedForm(_name, "");
    }
    else if (executor.getGrade() > _gradeToExecute) {
        throw Bureaucrat::GradeTooLowException(_name, ": The grade is too low to sign this form");
    }
    std::cout << COLOR_MSG_TESTING << executor.getName() << "is about to execute " << _name << TEXT_RESET << std::endl;
    action();
}

void    AForm::handleException(const std::exception& ex) {
    std::cout << COLOR_MSG_EXCEPTIONS << "Exception caught: " << ex.what() << TEXT_RESET << std::endl;
}


AForm::GradeTooHighException::GradeTooHighException(const std::string &name, const std::string &cons) : std::invalid_argument(name + " grade is too high" + cons) { }

AForm::GradeTooLowException::GradeTooLowException(const std::string &name, const std::string &extra) : std::invalid_argument(name + " grade is too low " + extra) { }

AForm::AlreadySignedException::AlreadySignedException(const std::string &name, const std::string &extra) : std::invalid_argument(name + "" + extra) { }

AForm::TryingToExecNonSignedForm::TryingToExecNonSignedForm(const std::string &name, const std::string &extra) : std::invalid_argument(name + " " + extra) { }

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

std::ostream& operator<<(std::ostream &os, const AForm &src) {
    os << "Name: " << src.getName() << std::endl;
    os << "Grade To Sign: " << src.getGradeToSign() << std::endl;
    os << "Grade To Execute: " << src.getGradeToExecute() << std::endl;
    os << "Is Signed: ";
    src.getIsSigned() ? os << "Yes" : os << "No";
    os << std::endl;
    return os;
}
// std::ostream  &AForm::print(std::ostream& os) const {
//     // os << "Name: " << getName() << std::endl;
//     // os << "Grade To Sign: " << getGradeToSign() << std::endl;
//     // os << "Grade To Execute: " << getGradeToExecute() << std::endl;
//     // os << "Is Signed: ";
//     // getIsSigned() ? os << "Yes" : os << "No";
//     // os << std::endl;
//     os << "TEST" << std::endl;
//     return os;
// }

/*__________________________________________
|_________Stream Operator Overloads_________|
*/

// std::ostream& operator<<(std::ostream& os, const AForm& src) {
//     os << "Name: " << src.getName() << std::endl;
//     os << "Grade To Sign: " << src.getGradeToSign() << std::endl;
//     os << "Grade To Execute: " << src.getGradeToExecute() << std::endl;
//     os << "Is Signed: ";
//     src.getIsSigned() ? os << "Yes" : os << "No";
//     os << std::endl;
//     return os;
// }