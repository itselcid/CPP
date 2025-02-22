#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "iostream"
#include "string"
class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &obj);
    Animal &operator=(const Animal &obj);
    ~Animal();

    void makeSound() const;
    std::string getType() const;
};

#endif