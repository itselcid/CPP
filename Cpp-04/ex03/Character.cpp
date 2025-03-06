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
            if (materias[i] != NULL)
                delete materias[i];

            materias[i] = NULL;
            if (obj.materias[i] != NULL)
                materias[i] = obj.materias[i]->clone();
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
        if (materias[i] != NULL)
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
    if (m == NULL)
        return;

    int i = 0;
    while (i < 4)
    {
        if (materias[i] == m)
            return;
        i++;
    }

    i = 0;
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

int Character::arraySize = 0;
AMateria **Character::deletedMaterias = NULL;

void Character::expandArray()
{
    if (deletedMaterias == NULL)
    {
        deletedMaterias = new AMateria *[1];
        return;
    }

    AMateria **newArray = new AMateria *[arraySize + 1];
    for (int i = 0; i < arraySize; i++)
    {
        newArray[i] = deletedMaterias[i];
    }

    delete[] deletedMaterias;
    deletedMaterias = newArray;
}

void Character::storeMateria(AMateria *m)
{
    if (!m)
        return;

    if (deletedMaterias == NULL)
        expandArray();
    else
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (deletedMaterias[i] == m)
                return;
        }
        expandArray();
    }
    deletedMaterias[arraySize++] = m;
}

void Character::cleanupMaterias()
{
    if (!deletedMaterias)
        return;

    for (int i = 0; i < arraySize; i++)
    {
        if (deletedMaterias[i])
            delete deletedMaterias[i];
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
