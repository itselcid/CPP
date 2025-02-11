#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed{
    int value;
    static const int  fractionalBits=8;

    public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& obj);
    Fixed& operator = (const Fixed& obj);
    ~Fixed();

    float toFloat(void) const;
    int toInt(void) const;
    int  getRawBits(void) const;
    void setRawBits(int const raw);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif