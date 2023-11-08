/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 19:19:19 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 19:26:01 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) { 
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << DEBUG << "FragTrap " << _name << " is born!" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap &src) : ClapTrap(src) { *this = src; }

FragTrap::~FragTrap() {
    std::cout << DEBUG << "FragTrap " << _name << " was buried!" << RESET << std::endl;
}

FragTrap &FragTrap::operator=( FragTrap &src ){
    if (this != &src ) {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return (*this);
}

void FragTrap:: attack(const std::string &target) {
    if (_energyPoints > 0) {
        _energyPoints -= 1;
        std::cout << DAMAGE << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
    }
    else 
        std::cout << "FragTrap " << _name << " has no energy to attack!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << CURE << "FragTrap " << _name << " has entered in High Five mode!" << RESET << std::endl;
}
