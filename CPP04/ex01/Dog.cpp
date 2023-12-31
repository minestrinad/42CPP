/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:40 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:55:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( ) : Animal( ) { 
    _brain = new Brain;
    _type = "dog";
    std::cout << DEBUG << "A new dog has been allocated" << RESET << std::endl;
}

Dog::Dog( std::string type ) : Animal(type) {
    _brain = new Brain;
    std::cout << DEBUG << "A new dog has been allocated" << RESET << std::endl;
}

Dog::Dog( Dog &src ) : Animal (src) {
    _brain = src._brain;
    std::cout << DEBUG << "A dog has been copied" << RESET << std::endl;
}

Dog::~Dog( ) { 
    delete _brain;
    std::cout << DEBUG << "A dog has been deallocated" << RESET << std::endl;
}

void Dog::makeSound( ) const {
    std::cout << "is barking" << std::endl;
}

std::string Dog::getType() const {
    return _type;
}