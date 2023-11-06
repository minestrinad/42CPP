/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:11 by everonel          #+#    #+#             */
/*   Updated: 2023/11/06 12:47:56 by everonel         ###   ########.fr       */
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
        Fixed &operator=( Fixed const &right_value );
        int getRawBits( ) const;
        void setRawBits(int const raw);
        float toFloat( ) const;
        int toInt( ) const;
    
    private:
        int					_fixed_value;
        static const int	_fractional_bits = 8;
};

std::ostream& operator<<( std::ostream &out, Fixed const &fixed );

#endif