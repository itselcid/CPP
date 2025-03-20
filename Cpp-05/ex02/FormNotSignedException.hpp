#pragma once
#include <exception>

class FormNotSignedException : public std::exception
{
public:
    const char *what() const throw() ;
};