/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:12 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:46:00 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( ) : AMateria() {
    _type = "ice";
    std::cout << DEBUG  << "A Ice has been allocated" << RESET << std::endl;
}

Ice::Ice(Ice &src) {
    *this = src;
    std::cout << DEBUG  << "A Ice has been copied" << RESET << std::endl;
}

Ice::~Ice( ) {
    std::cout << DEBUG  << "A Ice has been deallocated" << RESET << std::endl;
}

std::string const &Ice::getType() const {
    return _type;
}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

AMateria *Ice::clone() const{
    AMateria *clone = new Ice( );
    return clone;
}

