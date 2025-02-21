#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    Name = "Deafult";
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;  
    std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string _name)
{
    Name = _name;
    hit_points = 10;
    energy_points = 10;
    attack_damage = 0;  
    std::cout << "constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    Name = obj.Name;
    hit_points = obj.hit_points;
    energy_points = obj.energy_points;
    attack_damage = obj.attack_damage;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = obj;
}
ClapTrap::~ClapTrap()
{
    std::cout << " Destructor called " << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hit_points > 0 && energy_points > 0)
    {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
        energy_points--;
    }
    else
        std::cout << "you dont have enough energy or hit points to attack :( " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= hit_points)
    {
        std::cout << "the hit is so hard that you are Dead now " << std::endl;
        hit_points = 0;
    }
    else
    {
        hit_points = hit_points - amount;
        std::cout << "you got hit by " << amount << " attack damage" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points > 0 && energy_points > 0)
    {
        std::cout << "repairing " << amount << " of hit points" << std::endl;
        hit_points = hit_points + amount;
        energy_points--;
    }
    else
        std::cout << "ClapTrap is exhausted " << std::endl;
}