/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:59:25 by everonel          #+#    #+#             */
/*   Updated: 2023/11/07 18:59:27 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << DEBUG << "ClapTrap " << _name << " is born!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src) { *this = src; }

ClapTrap::~ClapTrap() { 
    std::cout << DEBUG << "ClapTrap " << _name << " was buried!" << RESET << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src) {
    if (this != &src) {
        _name = src._name;
        _hitPoints = src._hitPoints;
        _energyPoints = src._energyPoints;
        _attackDamage = src._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(std::string const & target) {
    if (_energyPoints > 0) {
        _energyPoints -= 1;
        std::cout << DAMAGE << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
    }
    else 
        std::cout << "ClapTrap " << _name << " has no energy to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints > 0) {
        _hitPoints -= amount;
        std::cout << DAMAGE << "ClapTrap " << _name << " takes " << amount << " points of damage!" << RESET << std::endl;
        if (_hitPoints == 0)
            std::cout << "ClapTrap " << _name << " has died!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has died!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_energyPoints > 0) {
        _hitPoints += amount;
        _energyPoints -= 1;
        std::cout << CURE << "ClapTrap " << _name << " is repaired for " << amount << " points!" << RESET << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has no energy to be repaired" << std::endl;
}