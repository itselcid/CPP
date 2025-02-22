#include "Animal.hpp"

Animal::Animal()
{
    type = "Animal";
    std::cout << "Animal Default Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &obj)
{
    type = obj.type;
    return *this;
}

Animal::Animal(const Animal &obj)
{
    *this = obj;
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "animal sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}