#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    Animal::operator=(obj);
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "HAWWW HAWWW" << std::endl;
}