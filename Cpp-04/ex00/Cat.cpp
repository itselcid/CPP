#include "Cat.hpp"

Cat::Cat()
{
    type = "Cat";
    std::cout << "Cat Constructor Called" << std::endl;
}
Cat::Cat(const Cat &obj) : Animal(obj)
{
}
Cat &Cat::operator=(const Cat &obj)
{
    type = obj.type;
    return *this;
}
Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
}