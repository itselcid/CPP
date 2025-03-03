#include "AMateria.hpp"

AMateria::AMateria()
{
    type = "";
}
AMateria::AMateria(std::string const &type)
{
    this->type = type;
}
AMateria::AMateria(const AMateria &obj)
{
    type = obj.type;
};

AMateria &AMateria::operator=(const AMateria &obj)
{
    if (this != &obj)
    {
        type = obj.type;
    }
    return *this;
};

std::string const &AMateria::getType() const
{
    return type;
};

void AMateria::use(ICharacter &target)
{
    (void)target;
};

AMateria::~AMateria() 
{

};
