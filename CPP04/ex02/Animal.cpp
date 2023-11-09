/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:23:46 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:05:08 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal() { 
    _type = "Aanimal";
    std::cout << DEBUG << "A new Aanimal has been allocated" << RESET << std::endl;
}

AAnimal::AAnimal(std::string type){
    _type = type;
    std::cout << DEBUG << "New Aanimal of type: " << _type << " has been allocated" << RESET << std::endl;
}

AAnimal::AAnimal(AAnimal &src) { 
    *this = src;
    std::cout << DEBUG << "An Aanimal has been copied" << RESET << std::endl;    
}

AAnimal::~AAnimal() { 
    std::cout << DEBUG << "An Aanimal has been deallocated" << RESET << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal &src){
    _type = src._type;
    return *this;
}

void AAnimal::makeSound() const{
    std::cout << "AAnimal sounds" << std::endl;
}

std::string AAnimal::getType( ) const {
    return _type;
}