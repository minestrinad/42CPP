/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:18:52 by everonel          #+#    #+#             */
/*   Updated: 2023/09/22 02:55:14 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {}
Weapon::~Weapon() {}

Weapon::Weapon(std::string type) {
    this->_type = type;
}

void    Weapon::setType(std::string type) {
    this->_type = type;
}

const std::string &Weapon::getType() {
    return (this->_type);
}

Weapon& Weapon::operator=(const Weapon& weapon) {
    if (this != &weapon)
        this->_type = weapon._type;
    return *this;
}

