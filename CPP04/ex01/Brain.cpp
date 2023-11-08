/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:28:10 by everonel          #+#    #+#             */
/*   Updated: 2023/11/08 19:47:41 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( ) { 
    std::cout << "A new brain has spawned" << std::endl;
}

Brain::Brain( Brain &src ) { 
    *this = src; 
    std::cout << "A brain has been cloned!" << std::endl;
}

Brain::~Brain( ) { 
    std::cout << "A brain has been burned!" << std::endl;
}

Brain &Brain::operator=( Brain &src ) {
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = src._ideas[i];
    return *this;
}