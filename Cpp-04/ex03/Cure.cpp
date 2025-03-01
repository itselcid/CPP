#include "Cure.hpp"

Cure::Cure()
{
    type = "cure";
}
Cure::Cure(const Cure &obj) : AMateria(obj)
{
}

Cure& Cure::operator=(const Cure &obj)
{
    if(this != &obj)
    {
        AMateria::operator=(obj);
    }
    return *this;
}
Cure::~Cure()
{

}

AMateria *Cure::clone() const 
{
    return new Cure(*this);
};

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
