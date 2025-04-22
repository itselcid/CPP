#pragma once
#include <vector>

#include <list>
#include <iostream>

class Span
{
    std::vector<int> numbers;
    unsigned int max_size;
    Span();

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    void addNumber(int number);
    int shortestSpan();
    int longestSpan();
};
