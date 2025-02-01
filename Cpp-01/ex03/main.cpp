#include <iostream>
#include <string>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("moss hafi");
        HumanA bob("hamid", club);
        bob.attack();
        club.setType("moss madi");
        bob.attack();
    }
    {
        Weapon club = Weapon("zerwata");
        HumanB jim("omar");
         jim.setWeapon(club);
        jim.attack();
        club.setType("catana");
        jim.attack();
    }
    return 0;
}