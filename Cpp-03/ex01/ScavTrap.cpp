#include "ScavTrap.hpp"

ScavTrap::ScavTrap() 
{
    Name="default";
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) :ClapTrap(_name)
{
    Name = _name;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout <<"Scavtrap "<< Name << " constructor" <<std::endl;
};
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    ClapTrap::operator=(obj);
    return *this;
};

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
    std::cout << "ScavTrap " << Name << " copy constructor" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << Name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (hit_points > 0 && energy_points > 0)
    {
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
        energy_points--;
    }
    else
        std::cout << "ScavTrap doesn't have enough energy or hit points to attack!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}