#pragma once
#include <exception>

class GradeTooHighException : public std::exception
{
public:
    const char *what() const throw() ;
};