#include "HarlFilter.hpp"

int main(int ac , char **av)
{
    if(ac != 2)
    {
        std::cout << "Usage: ./harlFilter DEBUG or INFO or WARNING or ERROR" << std::endl;
        return 1;
    }
    HarlFilter harlfilter;
    
    harlfilter.complain(av[1]);

    
    return 0;
}