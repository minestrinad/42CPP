/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:24:55 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:11:13 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal() { }

WrongCat::WrongCat(std::string type): WrongAnimal(type) {
    std::cout << DEBUG << "A new Wrong cat is born!" << RESET << std::endl;
}

WrongCat::WrongCat(WrongCat &src): WrongAnimal(src) { 
    std::cout << DEBUG << "A Wrong cat has been cloned :O" << RESET << std::endl;
}

WrongCat::~WrongCat() { 
    std::cout << DEBUG << "A Wrong cat is dead! :(" << RESET << std::endl;
}

void WrongCat::makeSound() const {
    std::cout << "mew mew :3" << std::endl;
}

std::string WrongCat::getType( ) const {
    return _type;
}
