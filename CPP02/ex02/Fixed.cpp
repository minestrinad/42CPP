/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:09 by everonel          #+#    #+#             */
/*   Updated: 2023/11/06 19:11:58 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ------->constructors and destructor      
Fixed::Fixed( ) : _fixed_value(0) {
    std::cout << DEBUG << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed( int const n ) : _fixed_value(n << _fractional_bits){
    std::cout << DEBUG << "from Int constructor called" << RESET << std::endl;
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

// -------*------->The assignation operator overload
Fixed &Fixed::operator=( Fixed const &src ) {
    std::cout << DEBUG << "Assignation operator called" << RESET << std::endl;
    if (this != &src)
        _fixed_value = src.getRawBits();
    return (*this);
}

// -------*------->The 4 arithmetic operators: +, -, *, and /
Fixed Fixed::operator+( Fixed const &src ) {
    return (Fixed (this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-( Fixed const &src ) {
    return (Fixed (this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*( Fixed const &src ) {
    return (Fixed (this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/( Fixed const &src ) {
    return (Fixed (this->toFloat() / src.toFloat()));
}


// -------*------->The 6 comparison operators: ==, !=, <=, >=, < and >
bool Fixed::operator==( Fixed const &src) {
    if (this->getRawBits() == src.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=( Fixed const &src ) {
    if (this->getRawBits() != src.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=( Fixed const &src ) {
    if (this->getRawBits() <= src.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=( Fixed const &src ) {
    if (this->getRawBits() >= src.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<( Fixed const &src ) {
    if (this->getRawBits() < src.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>( Fixed const &src ) {
    if (this->getRawBits() < src.getRawBits())
        return true;
    return false;
}

//  -------*------->The 4 increment and decrement operators: ++a, a++, --a, and a--
Fixed Fixed::operator++( int ) {
    float nbr = this->toFloat();
    this->_fixed_value++;
    return Fixed (nbr);
}

Fixed Fixed::operator--( int ) {
    int nbr = this->toFloat();
    this->_fixed_value--;
    return Fixed (nbr);
}

Fixed Fixed::operator++( ) {
    ++this->_fixed_value;
    return *this;
}

Fixed Fixed::operator--( ) { 
    --this->_fixed_value;
    return *this;
}


//  ------->min and max functions
Fixed &Fixed::min( Fixed &first, Fixed &second) {
    if (first < second)
        return first;
    return second;
}

Fixed const &Fixed::min( Fixed const &first, Fixed const &second ) {
    if (first.getRawBits() < second.getRawBits())
        return first;
    return second;    
}

Fixed &Fixed::max( Fixed &first, Fixed &second ) {
    if (first > second)
        return first;
    return second;
}

Fixed const &Fixed::max( Fixed const &first, Fixed const &second ) {
    if (first.getRawBits() > second.getRawBits())
        return first;
    return second;
}



//  ------->ostream overload
std::ostream& operator<<( std::ostream &out, Fixed const &fixed ) {
    out << fixed.toFloat();
    return (out);
}