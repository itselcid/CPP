#include "Point.hpp"
#include <iostream>

int main(void)
{
    Point A(4, 5);
    Point B(4, 3);
    Point C(1, 3);

    Point P(3, 4);

    if (bsp(A, B, C, P))
        std::cout << "the point P is inside the triangle ABC" << std::endl;
    else
        std::cout << "the point P is outside the triangle ABC" << std::endl;

    return 0;
}