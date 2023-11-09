/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:23:46 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:09:34 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() { 
    _type = "zoo";
    std::cout << DEBUG << "A new Wrong animal is born!" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
    _type = type;
    std::cout << DEBUG << "New Wrong animal of type: " << _type << " is born!" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &src) { 
    *this = src;
    std::cout << DEBUG << "An Wrong animal has been cloned!" << RESET << std::endl;    
}

WrongAnimal::~WrongAnimal() { 
    std::cout << DEBUG << "An Wrong animal is dead! :(" << RESET << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &src){
    _type = src._type;
    return *this;
}

void WrongAnimal::makeSound() const{
    std::cout << "Zoo sounds" << std::endl;
}

std::string WrongAnimal::getType( ) const {
    return _type;
}