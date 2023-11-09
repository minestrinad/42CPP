/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:28:10 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 22:52:53 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( ) { 
    std::cout << DEBUG << "A new brain has been allocated" << RESET << std::endl;
}

Brain::Brain( Brain &src ) { 
    *this = src; 
    std::cout << DEBUG << "A brain has been copied" << RESET << std::endl;
}

Brain::~Brain( ) { 
    std::cout << DEBUG << "A brain has been deallocated" << RESET << std::endl;
}

Brain &Brain::operator=( Brain &src ) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return *this;
}