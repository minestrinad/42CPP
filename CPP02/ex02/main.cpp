#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a;
    Fixed b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );
    std::cout << "      SUMS" << std::endl;
    std::cout << a + b << std::endl;
    std::cout << b + c << std::endl;
    std::cout << "      SUBTRACTIONS" << std::endl;
    std::cout << a - b << std::endl;
    std::cout << b - c << std::endl;
    std::cout << "      MULTIPLICATIONS" << std::endl;
    std::cout << a * b << std::endl;
    std::cout << b * c << std::endl;
    std::cout << "      DIVISIONS" << std::endl;
    std::cout << a / b << std::endl;
    std::cout << b / c << std::endl;
    
    Fixed g;
    Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << g << std::endl;
    std::cout << ++g << std::endl;
    std::cout << g << std::endl;
    std::cout << g++ << std::endl;
    std::cout << g << std::endl;
    std::cout << f << std::endl;
    std::cout << Fixed::max( g, f ) << std::endl;
    return 0;
}
