#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    Animal::operator=(obj);
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MEOWW MEOWWW" << std::endl;
}