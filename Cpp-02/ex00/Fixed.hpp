#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed{
    int value;
    static const int  fractionalBits=8;

    public:
    Fixed();
    Fixed(const Fixed& obj);
    Fixed& operator = (const Fixed& obj);
    ~Fixed();

    int  getRawBits(void) const;
    void setRawBits(int const raw);

};


#endif