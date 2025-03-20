#include "GradeTooHighException.hpp"

const char *GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}