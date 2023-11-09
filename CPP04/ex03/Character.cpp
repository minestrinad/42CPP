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

/*Character(std::string);
Character(Character &);
~Character( );

std::string const & getName() const;
void                equip(AMateria *);
void                unequip(int);
void                use(int, ICharacter &);

Character &operator=(Character &);*/

Character::Character(std::string name) : _name(name) {
    for (int i = 0; i < 4;  i++)
        _inventory[i] = NULL;
    std::cout << DEBUG << "A Character has been allocated" << RESET << std::endl;
}

Character::Character(Character &src) {
    *this = src; 
    std::cout << DEBUG << "A Character has been copied" << RESET << std::endl;
}

Character::~Character() { 
    std::cout << DEBUG << "A Character has been deallocated" << RESET << std::endl;
}

std::string const &Character::getName() const {
    return _name;
}

void Character::equip(AMateria *obj) {
    _inventory[_inventory_index] = *obj;

}

Character &Character::operator=(Character &src) {
    _name = src._name;
    return *this;
}