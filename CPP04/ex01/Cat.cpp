/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:19:07 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal() { 
    _type = "cat";
}

Cat::Cat(std::string type): Animal(type) {
    std::cout << DEBUG << "A new cat is born!" << RESET << std::endl;
}

Cat::Cat(Cat &src): Animal(src) { 
    std::cout << DEBUG << "A cat has been cloned :O" << RESET << std::endl;
}

Cat::~Cat() { 
    std::cout << DEBUG << "A cat is dead! :(" << RESET << std::endl;
}

void Cat::makeSound() const {
    std::cout << "mew mew :3" << std::endl;
}

std::string Cat::getType( ) const {
    return _type;
}
