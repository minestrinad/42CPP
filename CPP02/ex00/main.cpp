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

#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed b( a );
    Fixed c;

    a.setRawBits( 10 );
    b.setRawBits( 20 );
    std::cout << "Fixed a = "<< a.getRawBits() << std::endl;
    std::cout << "c = a ";
    c = a;
    std::cout << "Fixed c = "<< c.getRawBits() << std::endl;
    std::cout << "Fixed b = "<< b.getRawBits() << std::endl;
    std::cout << "c = b ";
    c = b;
    std::cout << "Fixed c = "<< c.getRawBits() << std::endl;
    return 0;
}

// int main( ) {
//     Fixed a;
//     Fixed b( a );
//     Fixed c;
//     c = b;

//     std::cout << a.getRawBits() << std::endl;
//     std::cout << b.getRawBits() << std::endl;
//     std::cout << c.getRawBits() << std::endl;
    
//     a.setRawBits( 10 );
//     std::cout << a.getRawBits() << std::endl;
//     b = a;
//     std::cout << b.getRawBits() << std::endl;
//     return 0;
// }