/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:09 by everonel          #+#    #+#             */
/*   Updated: 2023/10/24 13:29:18 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
    _fixed_point_value = 0;
}

Fixed::Fixed(Fixed const &src) {
    *this = src;
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(Fixed const &right_value) {
    if (this != &right_value)
        _fixed_point_value = right_value._fixed_point_value;
    return (*this);
}

void Fixed::setRawBits(int const raw) {
    _fixed_point_value = raw;
}

int Fixed::getRawBits(void) const {
    return (_fixed_point_value);
}
