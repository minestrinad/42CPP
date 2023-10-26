#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) { 
    _name = name;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << name << " is born!" << std::endl;
}

FragTrap::FragTrap(FragTrap &src): ClapTrap(src) { }

FragTrap::~FragTrap() { }

void FragTrap::attack(const std::string &target) {
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::getDamage(int amount) {
    std::cout << "FragTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(int amount) {
    std::cout << "FragTrap " << _name << " is repaired for " << amount << " points!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << _name << " has entered in High Five mode!" << std::endl;
}
