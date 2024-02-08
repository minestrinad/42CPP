/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:28:44 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 20:42:56 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate() {
    Base *newBase;
    int random = rand() % 3;
    if (random == 0)
        newBase = new A;
    else if (random == 1)
        newBase = new B;
    else
        newBase = new C;
    return (newBase);
}

void identify(Base *p) {
    try {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        throw std::invalid_argument("Invalid argument");
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }       
}

void identify(Base &p) {
        identify(&p);
}