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

//  ------->constructors and destructor
Fixed::Fixed( ) : _fixed_value(0) {
    std::cout << DEBUG << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( int const n ) : _fixed_value(n << _fractional_bits){
    std::cout << DEBUG << "from int constructor called" << RESET << std::endl;
}

Fixed::Fixed( float const n ) : _fixed_value(roundf(n *(1 << _fractional_bits))) {
    std::cout << DEBUG << "from float constructor called" << RESET << std::endl;
}

Fixed::Fixed( Fixed const &src ) {
    *this = src;
    std::cout << DEBUG << "Copy constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
    std::cout << DEBUG << "Destructor called" << RESET << std::endl;
}



//  ------->setters and getters
void Fixed::setRawBits( int const raw ) {
    _fixed_value = raw;
}

int Fixed::getRawBits( ) const {
    return (_fixed_value);
}



//  ------->conversions
float Fixed::toFloat( ) const {
    return static_cast<float>(_fixed_value) / (1 << _fractional_bits);
}

int Fixed::toInt( ) const {
    return _fixed_value / (1 << _fractional_bits);
}



//  ------->overload operators
Fixed &Fixed::operator=( Fixed const &src ) {
    std::cout << DEBUG << "Assigment operator called" << RESET << std::endl;
    if (this != &src)
        _fixed_value = src.getRawBits();
    return (*this);
}


// ------->overload print operators
std::ostream& operator<<( std::ostream &out, Fixed const &fixed ) {
    out << fixed.toFloat();
    return (out);
}