#include "Character.hpp"

Character::Character()
{
    name = "Default";
    materias[0] = NULL;
    materias[1] = NULL;
    materias[2] = NULL;
    materias[3] = NULL;
}

Character::Character(std::string _name)
{
    name = _name;
    materias[0] = NULL;
    materias[1] = NULL;
    materias[2] = NULL;
    materias[3] = NULL;
}
Character::Character(const Character &obj)
{
    name = obj.name;
    int i = 0;
    while (i < 4)
    {
        materias[i] = NULL;
        if (obj.materias[i] != NULL)
            materias[i] = obj.materias[i]->clone();
        i++;
    }
}
Character &Character::operator=(const Character &obj)
{
    if (this != &obj)
    {
        name = obj.name;
        int i = 0;
        while (i < 4)
        {
            delete materias[i];
            if (obj.materias[i] != NULL)
                materias[i] = obj.materias[i]->clone();
            else
                materias[i] = NULL;
            i++;
        }
    }
    return *this;
}

Character::~Character()
{
    int i = 0;
    while (i < 4)
    {
        delete materias[i];
        i++;
    }
   
}

std::string const &Character::getName() const
{
    return name;
}
void Character::equip(AMateria *m)
{
    int i = 0;
    while (i < 4)
    {
        if (materias[i] == m)
            return;
        i++;
    }
    i = 0;
    if (m != NULL)
    {
        while (i < 4)
        {
            if (materias[i] == NULL)
            {
                materias[i] = m;
                break;
            }
            i++;
        }
    }
}

int Character::arraySize = 0;
AMateria **Character::deletedMaterias = new AMateria *[1];

void Character::expandArray()
{
    AMateria **newArray = new AMateria *[arraySize + 1];
    int i = 0;
    while (i < arraySize)
    {
        newArray[i] = deletedMaterias[i];
        i++;
    }

    delete[] deletedMaterias;
    deletedMaterias = newArray;
}

void Character::storeMateria(AMateria *m)
{
    if (!m)
        return;

    int i = 0;
    while (i < arraySize)
    {
        if (deletedMaterias[i] == m)
            return;
        i++;
    }
    expandArray();
    deletedMaterias[arraySize++] = m;
}

void Character::cleanupMaterias()
{
    int i = 0;
    while (i < arraySize)
    {
        delete deletedMaterias[i];
        i++;
    }

    delete[] deletedMaterias;
}
void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && materias[idx] != NULL)
    {
        storeMateria(materias[idx]);
        materias[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && materias[idx] != NULL)
    {
        materias[idx]->use(target);
    }
}
