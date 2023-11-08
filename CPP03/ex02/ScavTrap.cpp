/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:07:50 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 19:26:12 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { 
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << DEBUG << "ScavTrap " << _name << " is born!" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src) { *this = src; }

ScavTrap::~ScavTrap() {
    std::cout << DEBUG << "ScavTrap " << _name << " was buried!" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=( ScavTrap &src ){
    if (this != &src ) {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return (*this);
}

void ScavTrap:: attack(const std::string &target) {
    if (_energyPoints > 0) {
        _energyPoints -= 1;
        std::cout << DAMAGE << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
    }
    else 
        std::cout << "ScavTrap " << _name << " has no energy to attack!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << CURE << "ScavTrap " << _name << " has entered in Gate keeper mode!" << RESET << std::endl;
}