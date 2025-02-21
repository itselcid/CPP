#include"FragTrap.hpp"

FragTrap::FragTrap()
{
    Name="default";
    hit_points = 100;
    energy_points = 100;
    attack_damage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    Name = _name;
    hit_points = 100;
    energy_points = 50;
    attack_damage = 20;
    std::cout <<"FragTrap "<< Name << " constructor" <<std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    ClapTrap::operator=(obj);
    return *this;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
    std::cout <<"FragTrap "<< Name << " copy constructor" <<std::endl;
}
FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called " << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " asalam aalaykom ✋" << std::endl;
}

