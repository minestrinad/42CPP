/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:12 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 19:06:48 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( ) : AMateria("ice") {
    std::cout << DEBUG << "An Ice has been allocated" << RESET << std::endl;
}

Ice::~Ice( ) {
    std::cout << DEBUG << "An Ice has been deallocated" << RESET << std::endl;
}

AMateria *Ice::clone() const {
    return new Ice ( );
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice &Ice::operator=( const Ice &src ) {
    (void) src;
    return *this;
}


