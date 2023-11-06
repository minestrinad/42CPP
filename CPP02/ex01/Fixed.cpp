/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:09 by everonel          #+#    #+#             */
/*   Updated: 2023/11/06 12:51:39 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( ) : _fixed_value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const n ) : _fixed_value(n << _fractional_bits){
    std::cout << "from Int constructor called" << std::endl;
}

Fixed::Fixed( float const n ) : _fixed_value(roundf(n *(1 << _fractional_bits))) {
    std::cout << "from float constructor called" << std::endl;
}

Fixed::Fixed( Fixed const &src ) {
    *this = src;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=( Fixed const &src ) {
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
        _fixed_value = src.getRawBits();
    return (*this);
}

void Fixed::setRawBits( int const raw ) {
    _fixed_value = raw;
}

int Fixed::getRawBits( ) const {
    return (_fixed_value);
}

float Fixed::toFloat( ) const {
    return static_cast<float>(_fixed_value) / (1 << _fractional_bits);
}

int Fixed::toInt( ) const {
    return _fixed_value / (1 << _fractional_bits);
}

std::ostream& operator<<( std::ostream &out, Fixed const &fixed ) {
    out << fixed.toFloat();
    return (out);
}