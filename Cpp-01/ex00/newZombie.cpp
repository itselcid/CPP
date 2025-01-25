#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie* zombiealloc=new Zombie(name);
	return zombiealloc;
}
