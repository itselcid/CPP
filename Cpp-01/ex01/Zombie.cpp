#include"Zombie.hpp"
Zombie::Zombie()
{
	
}
void Zombie::name_zombie(std::string _name)
{
	name=_name;
}
void Zombie::announce(void)
{
std::cout << name <<": BraiiiiiiinnnzzzZ" <<std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}