#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    // Test constructors and getters
    Fixed fixed1(42); // Integer constructor
    Fixed fixed2(3.14159f); // Float constructor

    // Test getRawBits and setRawBits
    std::cout << "fixed1 raw bits: " << fixed1.getRawBits() << std::endl;
    fixed1.setRawBits(12345);
    std::cout << "fixed1 raw bits after setRawBits: " << fixed1.getRawBits() << std::endl;

    // Test toFloat and toInt
    std::cout << "fixed1 as float: " << fixed1.toFloat() << std::endl;
    std::cout << "fixed2 as int: " << fixed2.toInt() << std::endl;

    // Test operator overloads
    Fixed fixed3 = fixed1; // Copy constructor
    std::cout << "fixed3 raw bits: " << fixed3.getRawBits() << std::endl;

    fixed2 = fixed3; // Assignment operator
    std::cout << "fixed2 raw bits after assignment: " << fixed2.getRawBits() << std::endl;

    // Test the << operator overload
    std::cout << "fixed1: " << fixed1 << std::endl;
    std::cout << "fixed2: " << fixed2 << std::endl;

    //                      Subject main
    // Fixed a;
    // Fixed const b( 10 );
    // Fixed const c( 42.42f );
    // Fixed const d( b );
    // a = Fixed( 1234.4321f );
    // std::cout << "a is " << a << std::endl;
    // std::cout << "b is " << b << std::endl;
    // std::cout << "c is " << c << std::endl;
    // std::cout << "d is " << d << std::endl;
    // std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    // std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    // std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    // std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}
