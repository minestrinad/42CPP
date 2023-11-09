/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:40 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:06:43 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( ) : AAnimal( ) { 
    _brain = new Brain;
    _type = "dog";
    std::cout << DEBUG << "A new dog has been allocated" << RESET << std::endl;
}

Dog::Dog( std::string type ) : AAnimal(type) {
    _brain = new Brain;
    std::cout << DEBUG << "A new dog has been allocated" << RESET << std::endl;
}

Dog::Dog( Dog &src ) : AAnimal (src) {
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