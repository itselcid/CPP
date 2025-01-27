#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon) : name(_name), weapon(weapon)
{
}

void HumanA::attack() 
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}