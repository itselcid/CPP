#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const int count = 4;
    Animal* animals[count];
    
    // Fill array with half dogs and half cats
    for(int i = 0; i < count; i++)
    {
        if(i < count/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Test deep copy for Dog
    Dog* originalDog = new Dog();
    Dog* copyDog = new Dog(*originalDog);  // Deep copy test
    delete originalDog;   // Original can be deleted and copy should still work
    delete copyDog;

    // Test deep copy for Cat
    Cat* originalCat = new Cat();
    Cat* copyCat = new Cat(*originalCat);  // Deep copy test
    delete originalCat;   // Original can be deleted and copy should still work
    delete copyCat;

    // Delete the array of animals
    for(int i = 0; i < count; i++)
        delete animals[i];

    return 0;
}