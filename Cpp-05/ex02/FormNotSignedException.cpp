#include "FormNotSignedException.hpp"

const char *FormNotSignedException::what() const throw()
{
    return "Form Is Not Signed";
}