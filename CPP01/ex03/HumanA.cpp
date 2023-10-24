/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:42:59 by everonel          #+#    #+#             */
/*   Updated: 2023/09/22 02:57:11 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}