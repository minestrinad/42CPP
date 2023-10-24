/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:11 by everonel          #+#    #+#             */
/*   Updated: 2023/10/24 13:25:54 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        int					_fixed_point_value;
        static const int	_fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);
        Fixed &operator=(Fixed const &right_value);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif