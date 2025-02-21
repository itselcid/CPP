#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : protected ClapTrap
{
public:
    ScavTrap(); 
    ScavTrap(std::string _name);
    ScavTrap(const ScavTrap &obj);  
    ScavTrap &operator=(const ScavTrap &obj);
    ~ScavTrap();

    void attack(const std::string &target);
    void guardGate();
};

#endif