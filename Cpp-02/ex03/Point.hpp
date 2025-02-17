#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{

    const Fixed x;
    const Fixed y;

public:
    Point();
    Point(const float _x, const float _y);
    Point(const Point &obj);
    Point &operator=(const Point &obj) ;
    ~Point();

    const Fixed getX() const;
    const Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif