#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog Constructor Called" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
    brain = new Brain(*obj.brain);
    std::cout << "Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &obj)
{
    if (this != &obj)
    {
        Animal::operator=(obj);
        delete brain;
        brain = new Brain(*obj.brain);
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog Destructor Called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "HAWWW HAWWW" << std::endl;
}