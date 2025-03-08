#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int count = 4;
    Animal* animals[count];
    

    for(int i = 0; i < count; i++)
    {
        if(i < count/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }


    Dog* originalDog = new Dog();
    Dog* copyDog = new Dog(*originalDog); 
    delete originalDog; 
    delete copyDog;


    Cat* originalCat = new Cat();
    Cat* copyCat = new Cat(*originalCat); 
    delete originalCat;   
    delete copyCat;

  
    for(int i = 0; i < count; i++)
        delete animals[i];

    return 0;
}