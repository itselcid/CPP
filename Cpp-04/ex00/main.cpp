#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
  

    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "j Type: " << j->getType() << std::endl;
    std::cout << "i Type: " << i->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    i->makeSound();   
    j->makeSound();   
    meta->makeSound(); 


    delete meta;
    delete j;
    delete i;

    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *wrongCat = new WrongCat();

    std::cout << "\nTypes:" << std::endl;
    std::cout << "wrongMeta Type: " << wrongMeta->getType() << std::endl;
    std::cout << "wrongCat Type: " << wrongCat->getType() << std::endl;

    std::cout << "\nSounds:" << std::endl;
    wrongCat->makeSound(); 
    wrongMeta->makeSound();


    delete wrongMeta;
    delete wrongCat;

    return 0;
}