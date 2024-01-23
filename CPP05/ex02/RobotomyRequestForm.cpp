/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:58:52 by everonel          #+#    #+#             */
/*   Updated: 2024/01/23 17:23:22 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target) { }

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) { *this = src; }

RobotomyRequestForm::~RobotomyRequestForm( ) { }

void    RobotomyRequestForm::execute( ) {
    std::cout << "non ho capito cosa deve fare questo coso ma per ora Drill Drill, " << _target << " has been robotomized successfully 50/100 of the time!!" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &src) {
    if (this == &src)
        return *this;
    _target = src._target;
    return *this;
}