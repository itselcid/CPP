#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T &a, T &b)
{
    if (a < b)
        return a;
    else
        return b;
}
template <typename t>
t max(t &a, t &b)
{
    if (a > b)
        return a;
    else
        return b;
}
