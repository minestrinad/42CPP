/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:23:46 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 18:43:25 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() { 
    _type = "zoo";
    std::cout << DEBUG << "A new animal is born!" << RESET << std::endl;
}

Animal::Animal(std::string type){
    _type = type;
    std::cout << DEBUG << "New animal of type: " << _type << " is born!" << RESET << std::endl;
}

Animal::Animal(Animal &src) { 
    *this = src;
    std::cout << DEBUG << "An animal has been cloned!" << RESET << std::endl;    
}

Animal::~Animal() { 
    std::cout << DEBUG << "An animal is dead! :(" << RESET << std::endl;
}

Animal &Animal::operator=(Animal &src){
    _type = src._type;
    return *this;
}

void Animal::makeSound() const{
    std::cout << "Zoo sounds" << std::endl;
}

std::string Animal::getType( ) const {
    return _type;
}