#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) :ClapTrap(_name)
{
    Name = _name;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout <<" Scavtrap "<< Name << " constructor" <<std::endl;
};
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    ClapTrap::operator=(obj);
    return *this;
};

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    *this = obj;
    std::cout << "ScavTrap " << Name << " copy constructor" << std::endl;
};