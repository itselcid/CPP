#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this=obj;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    value = n << fractionalBits;
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    value = roundf(n * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &obj)
{
    std::cout << "Copy assignment operator called" << std::endl;
    value = obj.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return value >> fractionalBits;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &output, const Fixed &fixed)
{
    output << fixed.toFloat();
    return output;
}