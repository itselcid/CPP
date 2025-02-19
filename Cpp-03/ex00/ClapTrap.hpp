#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap
{

    std::string Name;
    unsigned int hit_points;
    unsigned int energy_points;
    unsigned int attack_damage;

public:
    void attack(const std::string &target);
    void takeDamage(unsigned int amount);
};

#endif