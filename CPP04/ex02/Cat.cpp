/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 23:06:05 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): AAnimal() { 
    _type = "cat";
    _brain = new Brain( );
    std::cout << DEBUG << "A new cat has been allocated" << RESET << std::endl;
}

Cat::Cat(std::string type): AAnimal(type) {
    _brain = new Brain( );
    std::cout << DEBUG << "A new cat has been allocated" << RESET << std::endl;
}

Cat::Cat(Cat &src): AAnimal(src) { 
    _brain = src._brain;
    std::cout << DEBUG << "A cat has been copied" << RESET << std::endl;
}

Cat::~Cat() { 
    delete _brain;
    std::cout << DEBUG << "A cat has been deallocated" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << "is meowing" << std::endl;
}

std::string Cat::getType( ) const {
    return _type;
}
