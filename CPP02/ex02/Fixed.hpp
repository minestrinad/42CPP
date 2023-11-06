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

class Fixed
{
    public:
        Fixed( );
        Fixed( Fixed const &src );
        Fixed( int const n );
        Fixed( float const n );
        ~Fixed( );
        Fixed   &operator=( Fixed const & );
        
        Fixed   operator+( Fixed const & );
        Fixed   operator-( Fixed const & );
        Fixed   operator*( Fixed const & );
        Fixed   operator/( Fixed const & );

        Fixed   operator++( int );
        Fixed   operator--( int );
        Fixed   operator++( );
        Fixed   operator--( );
        

        bool    operator==( Fixed const &);
        bool    operator!=( Fixed const &);
        bool    operator<=( Fixed const &);
        bool    operator>=( Fixed const &);
        bool    operator<( Fixed const &);
        bool    operator>( Fixed const &);

        /*A static member function min that takes as parameters two references on fixed-point
numbers, and returns a reference to the smallest one.

•A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.

•A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.

•A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.
*/
        Fixed static        &min( Fixed &, Fixed &);
        Fixed static const  &min( Fixed const &, Fixed const &);
        Fixed static        &max( Fixed &, Fixed &);
        Fixed static const  &max( Fixed const &, Fixed const &);


        int     getRawBits( ) const;
        void    setRawBits(int const raw);
        float   toFloat( ) const;
        int     toInt( ) const;
    
    private:
        int					_fixed_value;
        static const int	_fractional_bits = 8;
};

std::ostream& operator<<( std::ostream &out, Fixed const &fixed );

#endif