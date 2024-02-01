/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:52 by everonel          #+#    #+#             */
/*   Updated: 2024/01/27 21:23:34 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) : AForm(src), _target(src._target){ }

RobotomyRequestForm::~RobotomyRequestForm( ) { }

void    RobotomyRequestForm::action( ) const {
    std::cout << "non ho capito cosa deve fare questo metodo ma per ora Drill Drill, " << _target << " has been robotomized successfully 50/100 of the time!!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src) {
    if (this == &src)
        return *this;
    _target = src._target;
    return *this;
}