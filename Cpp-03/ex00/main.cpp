#include "ClapTrap.hpp"

int main()
{

    ClapTrap clap1("R2D2");
    ClapTrap clap2(clap1);
    clap1.attack("C3PO");
    clap1.takeDamage(5);    
    clap1.beRepaired(3);   
    for (int i = 1; i <= 11; i++)
    {
        std::cout << "Attack attempt " << i << ": ";
        clap1.attack("Target");
    }
    
    clap1.beRepaired(5);   
    clap2.takeDamage(15);   
    clap2.attack("Target");
    clap2.beRepaired(5);   
    
    return 0;
}




