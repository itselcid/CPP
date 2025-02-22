#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Constructor Called" << std::endl;
}
Dog::Dog(const Dog &obj) : Animal(obj)
{
}
Dog &Dog::operator=(const Dog &obj)
{
    type = obj.type;
    return *this;
}
Dog::~Dog()
{
    std::cout << "Dog Destructor Called" << std::endl;
}