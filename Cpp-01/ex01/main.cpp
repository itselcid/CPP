#include "Zombie.hpp"

int main()
{
	int n = 3;
	Zombie *zombies = zombieHorde(n, "omar");

	int i = 0;
	while (i < n)
	{
		zombies[i].announce();
		i++;
	};
	delete[] zombies;

	
	return 0;
}