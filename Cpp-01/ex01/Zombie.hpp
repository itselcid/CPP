#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include<iomanip>
#include<iostream>

class Zombie{
	std::string name;
	public:
	Zombie();
	~Zombie();
	void announce();
	void name_zombie(std::string _name);

};
Zombie* zombieHorde( int N, std::string name );

#endif