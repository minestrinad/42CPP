/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:40 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:42:01 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( ) : Animal( ) { 
    _type = "dog";
}

Dog::Dog( std::string type ) : Animal(type) {
    std::cout << DEBUG << "A new dog has been allocated" << RESET << std::endl;
}

Dog::Dog( Dog &src ) : Animal (src) {
    std::cout << DEBUG << "A dog has been copied" << RESET << std::endl;
}

Dog::~Dog( ) { 
    std::cout << DEBUG << "A dog has been allocated" << RESET << std::endl;
}

void Dog::makeSound( ) const {
    std::cout << "is barking" << std::endl;
}

std::string Dog::getType() const {
    return _type;
}