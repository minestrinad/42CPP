/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:55:41 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() { 
    _type = "cat";
    _brain = new Brain( );
    std::cout << DEBUG << "A new cat has been allocated" << RESET << std::endl;
}

Cat::Cat(std::string type): Animal(type) {
    _brain = new Brain( );
    std::cout << DEBUG << "A new cat has been allocated" << RESET << std::endl;
}

Cat::Cat(Cat &src): Animal(src) { 
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
