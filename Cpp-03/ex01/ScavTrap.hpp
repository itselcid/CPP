#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap(std::string _name);
    ScavTrap(const ScavTrap &obj);  
    ScavTrap &operator=(const ScavTrap &obj);
    ~ScavTrap();

    void guardGate();
};

#endif