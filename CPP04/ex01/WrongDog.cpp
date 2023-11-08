/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongDog.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:54:40 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:10:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongDog.hpp"

WrongDog::WrongDog( ) : WrongAnimal( ) { }

WrongDog::WrongDog( std::string type ) : WrongAnimal(type) {
    std::cout << DEBUG << "A new Wrong dog is born!" << RESET << std::endl;
}

WrongDog::WrongDog( WrongDog &src ) : WrongAnimal (src) {
    std::cout << DEBUG << "A Wrong dog has been cloned :O" << RESET << std::endl;
}

WrongDog::~WrongDog( ) { 
    std::cout << DEBUG << "A Wrong dog is dead! :(" << RESET << std::endl;
}

void WrongDog::makeSound( ) const {
    std::cout << "wof wof!" << std::endl;
}

std::string WrongDog::getType() const {
    return _type;
}