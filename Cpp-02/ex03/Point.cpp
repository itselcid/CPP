#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {
}

Point::Point(const Point &obj) :x(obj.x) , y(obj.y){
}

Point& Point::operator=(const Point &obj) {
    (void)obj;
    return *this;
};

Point::~Point(){
};

const Fixed Point::getX() const {
    return this->x;
}

const Fixed Point::getY() const {
    return this->y;
}

Fixed area(const Point& a, const Point& b, const Point& c)
{
    float Ax = a.getX().toFloat();
    float Ay = a.getY().toFloat();
    float Bx = b.getX().toFloat();
    float By = b.getY().toFloat();
    float Cx = c.getX().toFloat();
    float Cy = c.getY().toFloat();
    
    float area = (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By)) / 2.0f;
    if (area < 0)
        area = -area;
    return Fixed(area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = area(a, b, c);
    Fixed areaABP = area(a,b,point);
    Fixed areaAPC = area(a,point,c);
    Fixed areaPBC = area(point,b,c);

    if((areaABP > 0 && areaAPC > 0 && areaPBC >0 ) && (areaABP + areaAPC + areaPBC == areaABC))
        return true;
    return false;
}

//Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2