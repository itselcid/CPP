#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    array = 0;
    _size = 0;
};
template <typename T>
Array<T>::Array(unsigned int n)
{
    array = new T[n];
    _size = n;
}
template <typename T>
Array<T>::Array(const Array<T> &other)
{
    array = new T[other._size];
    _size = other._size;
    int i = 0;
    while (i < _size)
    {
        array[i] = other.array[i];
        i++;
    }
};
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] array;
        array = new T[other._size];
        _size = other._size;
        int i = 0;
        while (i < _size)
        {
            array[i] = other.array[i];
            i++;
        }
    }
    return *this;
};

template <typename T>
T &Array<T>::operator[](int index)
{
    if (index >= _size || index < 0)
        throw std::out_of_range("Index is out of range");
    return array[index];
}
template <typename T>
int Array<T>::size() const
{
    return _size;
}
template <typename T>
Array<T>::~Array()
{
    delete[] array;
}