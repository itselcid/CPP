#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    type = "";
    std::cout << "WrongAnimal Constructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    type = obj.type;
    return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    *this = obj;
    std::cout << "WrongAnimal Copy Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor Called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}