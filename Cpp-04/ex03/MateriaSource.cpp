#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        matrias[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    int i = 0;
    while (i < 4)
    {
        matrias[i] = NULL;
        if (obj.matrias[i] != NULL)
            matrias[i] = obj.matrias[i]->clone();
        i++;
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    if (this != &obj)
    {
        int i = 0;
        while (i < 4)
        {
            delete matrias[i];
            if (obj.matrias[i] != NULL)
                matrias[i] = obj.matrias[i]->clone(); 
            else 
                matrias[i] = NULL;
            i++;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    while (i < 4)
    {
        delete matrias[i];
        i++;
    }
}

void MateriaSource::learnMateria(AMateria *m)
{
    if (!m)
        return;
        
    int i = 0;
    while (i < 4)
    {
        if (matrias[i] == NULL)
        {
            matrias[i] = m->clone();
            return;
        }
        i++;
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i = 0;
    while (i < 4)
    {
        if (matrias[i] != NULL && matrias[i]->getType() == type)
            return matrias[i]->clone();
        i++;
    }
    return NULL;
}
