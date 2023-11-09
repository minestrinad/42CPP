/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:37:10 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 13:44:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) { 
    _type = type;
    std::cout << DEBUG << "An AMateria has been allocated" << RESET << std::endl;
}

AMateria::~AMateria() { 
    std::cout << DEBUG  << "An AMateria has been deallocated" << RESET << std::endl;
}

std::string const & AMateria::getType() const {
    return _type;
} //Returns the materia type


void AMateria::use(ICharacter& target) {
    std::cout << "Tanto non vedrai mai"<< std::endl; 
}
