#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

    Dog* originalDog = new Dog();
    Dog* copyDog = new Dog(*originalDog);  
    delete originalDog;   
    delete copyDog;

    Cat* originalCat = new Cat();
    Cat* copyCat = new Cat(*originalCat); 
    delete originalCat; 
    delete copyCat;



    return 0;
}