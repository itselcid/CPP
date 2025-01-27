#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
    std::string type;

public:
    Weapon(std::string _type);
    const std::string &getType();
    void setType(std::string _type);
};

#endif