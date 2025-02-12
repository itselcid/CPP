#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	value = obj.getRawBits();
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
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (value);
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
	return (value >> fractionalBits);
}
// Comparison operators:
bool Fixed::operator>(const Fixed &rhs)
{
	return (value > rhs.getRawBits());
}
bool Fixed::operator>=(const Fixed &rhs)
{
	return (value >= rhs.getRawBits());
}
bool Fixed::operator<(const Fixed &rhs)
{
	return (value < rhs.getRawBits());
}
bool Fixed::operator<=(const Fixed &rhs)
{
	return (value <= rhs.getRawBits());
}
bool Fixed::operator==(const Fixed &rhs)
{
	return (value == rhs.getRawBits());
}
bool Fixed::operator!=(const Fixed &rhs)
{
	return (value != rhs.getRawBits());
}

// Arithmetic operators:

Fixed Fixed::operator+(const Fixed &rhs)
{
	Fixed tmp;
	tmp.value = this->value + rhs.getRawBits();
	return tmp;
}

Fixed Fixed::operator-(const Fixed &rhs)
{
	Fixed tmp;
	tmp.value = this->value - rhs.getRawBits();
	return tmp;
}

Fixed Fixed::operator*(const Fixed &rhs)
{
	Fixed result;
	long long temp = (long long)this->value * rhs.getRawBits();
	result.setRawBits(temp >> fractionalBits);
	return result;
}
Fixed Fixed::operator/(const Fixed &rhs)
{
	if (rhs.getRawBits() == 0)
	{
		std::cout << "Error: you cant divid by zero" << std::endl;
		return Fixed();
	}

	Fixed result;
	int temp = ((long long)this->value << fractionalBits) / rhs.getRawBits();
	result.setRawBits(temp);
	return result;
}

// increment/decrement

void Fixed::operator++()
{
	value++;
}

void Fixed::operator++()
{
	value--;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp = (*this);
	value++;
	return tmp;
}
Fixed Fixed::operator++(int)
{
	Fixed tmp;
	tmp = (*this);
	value--;
	return tmp;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}