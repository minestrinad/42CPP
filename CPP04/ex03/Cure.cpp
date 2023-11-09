/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:12 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 19:06:49 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( ) : AMateria("cure") {
    std::cout << DEBUG  << "A Cure has been allocated" << RESET << std::endl;
}

Cure::~Cure( ) {
    std::cout << DEBUG  << "A Cure has been deallocated" << RESET << std::endl;
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << "’s wounds *"<< std::endl;
}

AMateria *Cure::clone() const {
    return new Cure( );
}

Cure &Cure::operator=(const Cure &src) {
    (void)src;
    return *this;
}