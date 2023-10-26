/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:18:52 by everonel          #+#    #+#             */
/*   Updated: 2023/10/27 00:47:14 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() { }

Weapon::Weapon(std::string type) : _type(type) { }

Weapon::~Weapon() { }

void    Weapon::setType(std::string type) {
    _type = type;
}

const std::string &Weapon::getType() {
    return (_type);
}

Weapon& Weapon::operator=(const Weapon& copy) {
    if (this != &copy)
        _type = copy._type;
    return *this;
}

