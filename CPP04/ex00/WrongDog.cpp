/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:40 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:46:38 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog( ) : WrongAnimal( ) { 
    std::cout << DEBUG << "A new Wrong dog has been allocated" << RESET << std::endl;
}

WrongDog::WrongDog( std::string type ) : WrongAnimal(type) {
    std::cout << DEBUG << "A new Wrong dog has been allocated" << RESET << std::endl;
}

WrongDog::WrongDog( WrongDog &src ) : WrongAnimal (src) {
    std::cout << DEBUG << "A Wrong dog has been copoied" << RESET << std::endl;
}

WrongDog::~WrongDog( ) { 
    std::cout << DEBUG << "A Wrong dog has been deallocated" << RESET << std::endl;
}

void WrongDog::makeSound( ) const {
    std::cout << "is barking" << std::endl;
}

std::string WrongDog::getType() const {
    return _type;
}