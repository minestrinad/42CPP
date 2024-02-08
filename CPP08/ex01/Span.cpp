/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 01:04:07 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 21:20:52 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( unsigned int maxN ) : _maxN(maxN), _size(0) {
    _vec.reserve(maxN);
 }

Span::Span( const Span &src ) { *this = src; }

Span::~Span( ) { }

void    Span::addNumber( const int nbr ) {
    try{
        if (_size < (int)_maxN){
            std::vector<int>::iterator vecIt = _vec.begin();

            for (; vecIt != _vec.end() && nbr < *vecIt; vecIt++) { }
            _vec.insert(vecIt, nbr);
            _size++;
        }
        else
            throw std::length_error("Max number of elements reached");
    }
    catch (std::exception &e){
        std::cout << "Error: " << e.what() << std::endl;
    }
}

void    Span::addMoreNumbers( const std::vector<int> src ) {
    for (int i = 0; i < (int)src.capacity(); i++){
        addNumber (src[i]);
    }
}

int Span::shortestSpan() {
    try {
        if (_size <= 1 )
            throw std::invalid_argument("Not enough elements to compare");
        
        int shortest = std::numeric_limits<int>::max();
        std::vector<int>::iterator it = _vec.begin();

        for (int i = 0; i < (_size - 1); i++, it++){
            if ( *it - *(it + 1) < shortest){
                shortest = *it - *(it + 1);
                if (shortest == 0)
                    return 0;
            }
        }
        return shortest;
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

int Span::longestSpan( ) {
    try {
        if (_size <= 1)
            throw std::invalid_argument("Not enough elements to compare");
        return _vec[0] - _vec[_size - 1];
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

Span    &Span::operator=( const Span &src ) {
    if (this != &src) {
        for (int i = 0; i < _size; i++) {
            _vec[i] = src._vec[i];
        }
        _size = src._size;
    }
    return *this;
}


