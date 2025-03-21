#pragma once
#include <exception>
#include <string>

class FormNotSignedException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "Form is not signed";
    }
};