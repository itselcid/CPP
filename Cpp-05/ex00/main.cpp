
#include"Bureaucrat.hpp"
 

int main()
{
    try
    {
        Bureaucrat b("jj",166);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
}