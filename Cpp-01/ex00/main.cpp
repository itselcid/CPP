#include"Zombie.hpp"


int main()
{
    Zombie* zombie = newZombie("omar");    
    zombie->announce();
    delete zombie;                        
    randomChump("cid");
    return 0;
}