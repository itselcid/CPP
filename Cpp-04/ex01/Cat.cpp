#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat Constructor Called" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj)
{
    brain = new Brain(*obj.brain);
    std::cout << "Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &obj)
{
    if(this != &obj)
    {
        Animal::operator=(obj);
        delete brain;
        brain = new Brain(*obj.brain);
    } 
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor Called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "MEOWW MEOWWW" << std::endl;
}