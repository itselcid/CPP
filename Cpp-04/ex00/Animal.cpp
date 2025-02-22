#include"Animal.hpp"

Animal::Animal()
{
    type="Animal";
    std::cout <<"Animal Constructor Called" << std::endl;
}
Animal& Animal::operator=(const Animal &obj)
{
    type=obj.type;
    return *this;
}
Animal::Animal(const Animal &obj)
{
    *this=obj;
}
Animal::~Animal()
{
      std::cout <<"Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
    if(type=="Dog")
    {
        std::cout << " HAWW HAWWW" << std::endl;
    }
    else if(type=="Cat")
    {
        std::cout << " MEAWWWW  MEAWWWW"<< std::endl;
    }
    else
    std::cout << " Animal Sound" <<std::endl;
}
std::string Animal::getType() const
{
    return type;
}