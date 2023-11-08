/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:28:06 by everonel          #+#    #+#             */
/*   Updated: 2023/11/06 11:29:25 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b( a );
    
    std::cout << "Fixed a fixed_value = " << a.getRawBits() << std::endl;
    std::cout << "Fixed b fixed_value = " << b.getRawBits() << std::endl;
    a.setRawBits(42);
    Fixed c;
    c = a;
    std::cout << "Fixed a fixed_value = " << a.getRawBits() << std::endl;
    std::cout << "Fixed c fixed_value = " << c.getRawBits() << std::endl;

    //          subject test
    // Fixed a;
    // Fixed b( a );
    // Fixed c;
    // c = b;
    // std::cout << a.getRawBits() << std::endl;
    // std::cout << b.getRawBits() << std::endl;
    // std::cout << c.getRawBits() << std::endl;
    return 0;
}