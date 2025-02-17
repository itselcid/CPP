#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed()
{
	value = 0;
}

Fixed::Fixed(const Fixed &obj)
{
	value = obj.getRawBits();
}

Fixed::Fixed(const int n)
{

	value = n << fractionalBits;
}

Fixed::Fixed(const float n)
{
	value = roundf(n * (1 << fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &obj)
{
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
bool Fixed::operator>(const Fixed &rhs) const
{
	return (value > rhs.getRawBits());
}
bool Fixed::operator>=(const Fixed &rhs) const
{
	return (value >= rhs.getRawBits());
}
bool Fixed::operator<(const Fixed &rhs) const
{
	return (value < rhs.getRawBits());
}
bool Fixed::operator<=(const Fixed &rhs) const
{
	return (value <= rhs.getRawBits());
}
bool Fixed::operator==(const Fixed &rhs) const
{
	return (value == rhs.getRawBits());
}
bool Fixed::operator!=(const Fixed &rhs) const
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

Fixed &Fixed::operator++()
{
	++value;
	return (*this);
}

Fixed &Fixed::operator--()
{
	--value;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	value++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	value--;
	return temp;
}

std::ostream &operator<<(std::ostream &output, const Fixed &fixed)
{
	output << fixed.toFloat();
	return (output);
}

Fixed::~Fixed()
{

}

// Min/Max function
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	else
		return b;
}