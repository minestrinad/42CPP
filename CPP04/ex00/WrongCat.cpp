/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:45:37 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() { 
    std::cout << DEBUG << "A new wrong cat has been allocated" << RESET << std::endl;
}

WrongCat::WrongCat(std::string type): WrongAnimal(type) {
    std::cout << DEBUG << "A new wrong cat has been allocated" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat &src): WrongAnimal(src) { 
    std::cout << DEBUG << "A Wrong cat has been copied" << RESET << std::endl;
}

WrongCat::~WrongCat() { 
    std::cout << DEBUG << "A Wrong cat has been deallocated" << RESET << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "is meowing" << std::endl;
}

std::string WrongCat::getType( ) const {
    return _type;
}
