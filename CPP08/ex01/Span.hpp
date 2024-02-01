/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:57:56 by everonel          #+#    #+#             */
/*   Updated: 2024/02/01 14:26:37 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <limits>
# include <vector>

class Span
{
    private:
        unsigned int        _maxN; 
        std::vector<int>    _vec;
        int                 _size;

    public:
        Span( unsigned int );
        Span( const Span &);
        ~Span( );

        void    addNumber( const int );
        void    addMoreNumbers( const std::vector<int> );
        int     shortestSpan( );
        int     longestSpan( );

    Span    &operator=( const Span &);
};
#endif