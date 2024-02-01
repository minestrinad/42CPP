/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:37:28 by everonel          #+#    #+#             */
/*   Updated: 2024/01/31 23:35:28 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
// include for srand
# include <ctime>
// include for rand
# include <cstdlib>
// si puo' aggiungere il .tpp 
template <typename T> class Array {
    public:
        Array( );
        Array( unsigned int n);
        Array(Array const & src);
        ~Array( );

        Array &         operator=(const Array &rhs);
        T &             operator[]( int idx );
        unsigned int    size( ) const;
        
    private:
        unsigned int _size;
        T           *_array;
};

#include "Array.tpp"
#endif