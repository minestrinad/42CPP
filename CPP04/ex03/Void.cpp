/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Void.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:24:12 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:42:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Void.hpp"

Void::Void( ) : AMateria() {
    _type = "void";
    std::cout << DEBUG  << "A void has been allocated" << RESET << std::endl;
}

Void::Void(Void &src) : AMateria(src) {
    std::cout << DEBUG  << "A void has been copied" << RESET << std::endl;
}

Void::~Void() {
    std::cout << DEBUG  << "A void has been deallocated" << RESET << std::endl;
}

std::string const &Void::getType() const {
    return _type;
}

// void Ice::use(ICharacter &target) {
//     std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
// }

AMateria *Void::clone() const{
    AMateria *clone = new Void( );
    return clone;
}