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
            if (matrias[i] != NULL)
                delete matrias[i];

            matrias[i] = NULL;
            if (obj.matrias[i] != NULL)
                matrias[i] = obj.matrias[i]->clone();
            i++;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    int i = 0;
    int j;
    while (i < 4)
    {
        j = i +1;
        while (j < 4)
        {
            if (matrias[i] == matrias[j])
                matrias[i] = NULL;
            j++;
        }
        if(matrias[i])
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
            matrias[i] = m;
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
