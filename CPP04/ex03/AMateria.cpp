/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:37:10 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:49:10 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) { 
    _type = type;
    std::cout << "An AMateria has been allocated" << std::endl;
}

AMateria::AMateria(AMateria &src) { 
    *this = src; 
    std::cout << "An AMateria has been copied" << std::endl;
}

AMateria::~AMateria() { 
    std::cout << "An AMateria has been deallocated" << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
} //Returns the materia type

// AMateria*   Amateria::clone() const = 0;
void        AMateria::use(ICharacter& target) {
    std::cout << "AMataria of type: " << _type << " has been used on a character" << target.getName() << std::endl; 
}
AMateria &AMateria::operator=(AMateria &src){
    _type = src._type;
    return *this;
}
