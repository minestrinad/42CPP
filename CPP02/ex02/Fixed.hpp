/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:11 by everonel          #+#    #+#             */
/*   Updated: 2023/11/06 19:07:11 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RESET		"\033[0m"
# define DEBUG		"\033[33m"
# define TEST		"\033[32m"

class Fixed
{
    public:
    //  constructors and destructor
        Fixed( );
        Fixed( Fixed const &src );
        Fixed( int const n );
        Fixed( float const n );
        ~Fixed( );

    //  setters and getters
        int     getRawBits( ) const;
        void    setRawBits(int const raw);

    //  conversions
        float   toFloat( ) const;
        int     toInt( ) const;
    
    //  overload operators
        Fixed   &operator=( Fixed const & );
        //  The 4 arithmetic operators: +, -, *, and /    
        Fixed   operator+( Fixed const & );
        Fixed   operator-( Fixed const & );
        Fixed   operator*( Fixed const & );
        Fixed   operator/( Fixed const & );
        //  The 4 increment and decrement operators: ++a, a++, --a, and a--
        Fixed   operator++( int );
        Fixed   operator--( int );
        Fixed   operator++( );
        Fixed   operator--( );
        //  The 6 comparison operators: ==, !=, <=, >=, < and >
        bool    operator==( Fixed const &);
        bool    operator!=( Fixed const &);
        bool    operator<=( Fixed const &);
        bool    operator>=( Fixed const &);
        bool    operator<( Fixed const &);
        bool    operator>( Fixed const &);
    
    //  min and max functions
        Fixed static        &min( Fixed &, Fixed &);
        Fixed static const  &min( Fixed const &, Fixed const &);
        Fixed static        &max( Fixed &, Fixed &);
        Fixed static const  &max( Fixed const &, Fixed const &);

    private:
        int					_fixed_value;
        static const int	_fractional_bits = 8;
};

//  overload print operators
std::ostream& operator<<( std::ostream &out, Fixed const &fixed );

#endif