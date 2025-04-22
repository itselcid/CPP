#pragma once 
#include <cstddef>

template <typename T, typename F>
void iter(T *array, int len, F func)
{
    if (array == NULL || func == NULL)
        return;
    int i = 0;

    while (i < len)
    {
        func(array[i]);
        i++;
    }
}