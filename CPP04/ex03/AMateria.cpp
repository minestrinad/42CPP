/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 23:37:10 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 23:51:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

//          Costruttore
AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "An AMateria has been allocated" << std::endl;
}

//          Metodi
std::string const &AMateria::getType( ) const {
    return _type;
}


void AMateria::use( ICharacter &target) {
    std::cout << "An AMateria of type " << _type << " has been used on " << target.getName() << std::endl;
}