#include <iostream>
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    Fixed c(3.14f);
    

    std::cout << "\n=== Testing Arithmetic Operators ===" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    std::cout << "c + a = " << c + a << std::endl;
    std::cout << "c - a = " << c - a << std::endl;
    std::cout << "c * a = " << c * a << std::endl;
    std::cout << "c / b = " << c / b << std::endl;


    std::cout << "\n=== Testing Comparison Operators ===" << std::endl;
    std::cout << "c > a: " << (c > a) << std::endl;
    std::cout << "c < b: " << (c < b) << std::endl;
    std::cout << "c >= a: " << (c >= a) << std::endl;
    std::cout << "c <= b: " << (c <= b) << std::endl;
    std::cout << "c == a: " << (c == a) << std::endl;
    std::cout << "c != a: " << (c != a) << std::endl;


    std::cout << "\n=== Testing Increment/Decrement ===" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "--a: " << --a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a--: " << a-- << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "\n=== Testing Min/Max ===" << std::endl;
    std::cout << "min(a, c): " << Fixed::min(a, c) << std::endl;
    std::cout << "max(a, c): " << Fixed::max(a, c) << std::endl;
    std::cout << "min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "max(b, c): " << Fixed::max(b, c) << std::endl;
    
    return 0;
}
