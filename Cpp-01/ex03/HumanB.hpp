#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <iomanip>

class HumanB
{
    std::string name;
    Weapon *weapon;

public:
    HumanB(std::string name);
    void setWeapon(Weapon &_weapon);
    void attack();
};

#endif