#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { 
    _name = name;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << name << " is born!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &src) : ClapTrap(src) { }

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
}

void ScavTrap:: attack(const std::string &target) {
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::getDamage(int amount) {
    std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(int amount) {
    std::cout << "ScavTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << _name << " has entered in Gate keeper mode!" << std::endl;
}