/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:40 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:19:26 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( ) : Animal( ) { 
    _type = "dog";
}

Dog::Dog( std::string type ) : Animal(type) {
    std::cout << DEBUG << "A new dog is born!" << RESET << std::endl;
}

Dog::Dog( Dog &src ) : Animal (src) {
    std::cout << DEBUG << "A dog has been cloned :O" << RESET << std::endl;
}

Dog::~Dog( ) { 
    std::cout << DEBUG << "A dog is dead! :(" << RESET << std::endl;
}

void Dog::makeSound( ) const {
    std::cout << "wof wof!" << std::endl;
}

std::string Dog::getType() const {
    return _type;
}