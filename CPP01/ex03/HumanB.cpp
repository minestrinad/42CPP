/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:42:59 by everonel          #+#    #+#             */
/*   Updated: 2023/09/23 11:38:19 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
 
HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}
HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon& weapon) {
    this->_weapon = &weapon;
}  

void HumanB::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}