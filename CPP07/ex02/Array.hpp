/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:37:28 by everonel          #+#    #+#             */
/*   Updated: 2024/02/08 21:04:12 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

template <typename T> class Array {
    public:
        Array( ) : _size(0), _data(NULL) { }

        Array( unsigned int n) : _size(n) { 
            _data = new T[n];
            for (unsigned int i = 0; i < n; i++)
                _data[i] = T();
        }

        Array(Array const & src) { *this = src; }
        
        ~Array( ) { delete [] _data; }

        Array &         operator=(const Array &rhs) {
            if (this != &rhs) {
                _size = rhs.size();
                _data = new T[_size];
                for (unsigned int i = 0; i < _size; i++)
                    _data[i] = rhs._data[i];
            }
            return *this;
        }

        T &             operator[]( int idx ) {
            if (idx < 0 || idx >= (int)_size)
                throw std::out_of_range("Index out of range");
            return _data[idx];
        }
        
        unsigned int    size( ) const { return _size; }
        
    private:
        unsigned int _size;
        T           *_data;
};

#include "Array.tpp"
#endif