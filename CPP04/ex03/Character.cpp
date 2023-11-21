/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:10:25 by everonel          #+#    #+#             */
/*   Updated: 2023/11/09 11:18:09 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

//              costruttori
Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < DIM_INVENTORY;  i++)
        _inventory[i] = NULL;
    for (int i = 0; i < DIM_FLOOR; i++)
        _floor[i] = NULL;
    std::cout << DEBUG << "A Character has been allocated" << RESET << std::endl;
}

Character::Character(Character &src) {
    *this = src; 
    std::cout << DEBUG << "A Character has been copied" << RESET << std::endl;
}

//              distruttore
Character::~Character() { 
    std::cout << DEBUG << "A Character has been deallocated" << RESET << std::endl;
}

//              metodi
std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *obj) {
    int i = 0;

    while (_inventory[i] != NULL) 
        i++;
    if (i < DIM_INVENTORY)
    _inventory[i] = obj;
}

void Character::unequip( int idx ) {
    int i = 0;
    while (i < DIM_FLOOR && _floor[i] != NULL)
        i++;
    if (idx < DIM_INVENTORY && idx > -1) {
        _floor[i] = _inventory[idx];
        _inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target) {
    _inventory[idx]->use(target);
    this->unequip(idx);
}

//              overload
Character &Character::operator=(Character &src) {
    for (int i = 0; i < DIM_INVENTORY; i++){
        if (_inventory[i] != NULL)
            delete _inventory[i];
        _inventory[i] = src._inventory[i];
    }
    _name = src._name;
    return *this;
}