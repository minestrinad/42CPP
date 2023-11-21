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

Bureaucrat::Bureaucrat(std::string name, int grade) {
    _name = name;
    try
    {
        if (grade < 1)
            throw  GradeTooHighException( );
        if (grade > 150)
            throw GradeTooLowException( );
        _grade = grade;
        std::cout << COLOR_DEBUG << "Bureaucrat " << _name << " has been allocated with a grade of: " << _grade << COLOR_RESET << std::endl;
    }
    catch (std::exception& e) 
    {   
        std::cerr << COLOR_ERROR << e.what() << COLOR_RESET << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) { *this = src; }

Bureaucrat::~Bureaucrat( ) { 
    std::cout << COLOR_DEBUG << "Bureaucrat " << _name << " has been deallocated" << COLOR_RESET << std::endl;
}

/*----------------GETTER / SETTER*/
std::string Bureaucrat::getName( ) const {
    return _name;
}

int Bureaucrat::getGrade( ) const {
    return _grade;
}

/*--------------OTHER METHODS*/

void    Bureaucrat::decrementGrade( ) {
    try
    {
        std::cout << COLOR_DEBUG << "Trying to decrement grade: " << _grade << COLOR_RESET << std::endl;
        if (_grade == 150)
            throw GradeTooLowException( );
        _grade++;
        std::cout << COLOR_DEBUG << "Bureaucrat " << _name << " has been decremented to grade: " << _grade << COLOR_RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << COLOR_ERROR << e.what() << COLOR_RESET << std::endl;
    }
}

void    Bureaucrat::incrementGrade( ) {
    try
    {
        if (_grade == 1)
            throw GradeTooHighException( );
        _grade--;
        std::cout << COLOR_DEBUG << "Bureaucrat " << _name << " has been incremented to grade: " << _grade << COLOR_RESET << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << COLOR_ERROR << e.what() << COLOR_RESET << std::endl;
    }
}


/*-------------OPERATOR OVERLOADS*/
const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
    _name = src._name;
    _grade = src._grade;
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &src) {
    out << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
    return out;
}


/*-------------EXCEPTIONS*/
const char *Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade too low! the minimum grade is 150");
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade too high! the maximum grade is 1");
}