#pragma once
#include <stdexcept>


template <class T>
class Array
{

    T *array;
    int _size;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    T &operator[](int index);
    int size() const;
};

