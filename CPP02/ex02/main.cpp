#include "Fixed.hpp"

int main() {
    // Test constructors and getters
    std::cout << TEST << "Constructors and getters" << RESET << std::endl;
    Fixed fixed1;          
    Fixed fixed2(42); 
    Fixed fixed3(3.14159f);

    // Test getRawBits and setRawBits
    std::cout << TEST << "getRawBits and setRawBits" << RESET << std::endl;
    std::cout << "fixed1 raw bits: " << fixed1.getRawBits() << std::endl;
    fixed1.setRawBits(12345);
    std::cout << "fixed1 raw bits after setRawBits: " << fixed1.getRawBits() << std::endl;

    // Test toFloat and toInt
    std::cout << TEST << "toFloat and toInt" << RESET << std::endl;
    std::cout << "fixed2 as float: " << fixed2.toFloat() << std::endl;
    std::cout << "fixed3 as int: " << fixed3.toInt() << std::endl;

    // Test arithmetic operator overloads
    std::cout << TEST << "Arithmetic operator overloads" << RESET << std::endl;
    Fixed result = fixed2 + fixed3;
    std::cout << "fixed2 + fixed3: " << result << std::endl;
    
    result = fixed2 - fixed3;
    std::cout << "fixed2 - fixed3: " << result << std::endl;

    result = fixed2 * fixed3;
    std::cout << "fixed2 * fixed3: " << result << std::endl;

    result = fixed2 / fixed3;
    std::cout << "fixed2 / fixed3: " << result << std::endl;

    // Test increment and decrement operators
    std::cout << TEST << "Increment and decrement operators" << RESET << std::endl;
    Fixed fixed4 = fixed2;
    fixed4++;
    std::cout << "fixed2++: " << fixed4 << std::endl;

    Fixed fixed5 = fixed3;
    ++fixed5;
    std::cout << "++fixed3: " << fixed5 << std::endl;

    Fixed fixed6 = fixed2;
    fixed6--;
    std::cout << "fixed2--: " << fixed6 << std::endl;

    Fixed fixed7 = fixed3;
    --fixed7;
    std::cout << "--fixed3: " << fixed7 << std::endl;

    // Test comparison operators
    std::cout << TEST << "Comparison operators" << RESET << std::endl;
    std::cout << "fixed2 == fixed3: " << (fixed2 == fixed3) << std::endl;
    std::cout << "fixed2 != fixed3: " << (fixed2 != fixed3) << std::endl;
    std::cout << "fixed2 <= fixed3: " << (fixed2 <= fixed3) << std::endl;
    std::cout << "fixed2 >= fixed3: " << (fixed2 >= fixed3) << std::endl;
    std::cout << "fixed2 < fixed3: " << (fixed2 < fixed3) << std::endl;
    std::cout << "fixed2 > fixed3: " << (fixed2 > fixed3) << std::endl;

    // Test min and max functions
    std::cout << TEST << "Min and max functions" << RESET << std::endl;
    Fixed minResult = Fixed::min(fixed2, fixed3);
    Fixed maxResult = Fixed::max(fixed2, fixed3);

    std::cout << "Min(fixed2, fixed3): " << minResult << std::endl;
    std::cout << "Max(fixed2, fixed3): " << maxResult << std::endl;

    //       subject main
    // Fixed a;
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}

