/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:12 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:47:42 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( ) : AMateria() {
    _type = "cure";
    std::cout << DEBUG  << "A Cure has been allocated" << RESET << std::endl;
}

Cure::Cure(Cure &src) {
    *this = src;
    std::cout << DEBUG  << "A Cure has been copied" << RESET << std::endl;
}

Cure::~Cure() {
    std::cout << DEBUG  << "A Cure has been deallocated" << RESET << std::endl;
}

std::string const &Cure::getType() const {
    return _type;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *"<< std::endl;
}

AMateria *Cure::clone() const{
    AMateria *clone = new Cure( );
    return clone;
}