#ifndef CHARCTER_HPP
#define CHARCTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
    AMateria *materias[4];
    std::string name;

    static AMateria **deletedMaterias;
    static int arraySize;

public:
    Character();
    Character(std::string _name);
    Character(const Character &obj);
    Character &operator=(const Character &obj);
    ~Character();
    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);

    static void storeMateria(AMateria *m);
    static void cleanupMaterias();
    static void expandArray();
};

#endif