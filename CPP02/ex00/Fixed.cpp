/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:09 by everonel          #+#    #+#             */
/*   Updated: 2023/11/06 12:20:15 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( ) : _fixed_value(0) {
    std::cout << DEBUG << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( Fixed const &src ) : _fixed_value(src._fixed_value) {
    std::cout << DEBUG << "Copy constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << DEBUG << "Destructor called" << RESET << std::endl;
}


void Fixed::setRawBits( int const raw ) {
    _fixed_value = raw;
 }

int Fixed::getRawBits( ) const {
    return ( _fixed_value );
}

Fixed &Fixed::operator=( Fixed const &src ) {
    std::cout << DEBUG << "Assignment operator called" << RESET << std::endl;
    if (this != &src)
        _fixed_value = src.getRawBits();
    return (*this);
}