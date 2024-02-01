/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 23:00:28 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 23:48:29 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>Array<T>::Array( ) : _size(0), _array(new T[0]) { }

template<typename T>Array<T>::Array(unsigned int n) : _size(n), _array(new T[n]) { }

template<typename T>Array<T>::Array(Array const & src) : _size(src._size), _array(new T[src._size]) {
    for (unsigned int i = 0; i < src._size; i++)
        _array[i] = src._array[i];
}

template<typename T>Array<T>::~Array( ) { }

template<typename T>Array<T>   &Array<T>::operator=(const Array& src){
    for (unsigned int i = 0; i < src._size; i++)
        _array[i] = src._array[i];
    return *this;
}

template<typename T>T &         Array<T>::operator[]( int idx ) {
    try {
        if ( idx < 0 || idx >= (int)_size )
            throw std::exception();
        return _array[idx];
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return _array[0];
}

template<typename T>unsigned int    Array<T>::size( ) const { return _size; }