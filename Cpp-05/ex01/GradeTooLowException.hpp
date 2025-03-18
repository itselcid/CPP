#pragma once
#include <exception>

class GradeTooLowException : public std::exception
{
public:
    const char *what() const throw() ;
};