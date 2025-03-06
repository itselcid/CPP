#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    {
        std::cout << "==== Basic Functionality Test ====" << std::endl;
        IMateriaSource *src = new MateriaSource();
        Ice *a = new Ice();
        src->learnMateria(a);
        src->learnMateria(a);
        src->learnMateria(new Cure());

        ICharacter *me = new Character("me");
        AMateria *tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);

        ICharacter *bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);

        delete bob;
        delete me;
        delete src;
    }

    std::cout << "\n==== Edge Cases Test ====" << std::endl;

    {
        std::cout << "Test unequip and reequip:" << std::endl;

        Character *me = new Character("me");
        AMateria *ice = new Ice();

        std::cout << "Equipping ice..." << std::endl;
        me->equip(ice);
        me->use(0, *me);

        std::cout << "Unequipping ice..." << std::endl;
        me->unequip(0); 
        me->use(0, *me); 

   
        std::cout << "Equipping new ice..." << std::endl;
        ice = new Ice();
        me->equip(ice);
        me->use(0, *me);

        delete me; 
    }

    {
        std::cout << "\nTest deep copy of characters:" << std::endl;

        Character *original = new Character("original");
        original->equip(new Ice());
        original->equip(new Cure());

        std::cout << "Original character using skills:" << std::endl;
        original->use(0, *original);
        original->use(1, *original);

        std::cout << "Copying character..." << std::endl;
        Character *copy = new Character(*original);

        std::cout << "Copy character using skills:" << std::endl;
        copy->use(0, *copy);
        copy->use(1, *copy);

        std::cout << "Deleting original..." << std::endl;
        delete original;

        std::cout << "Copy still works after original is deleted:" << std::endl;
        copy->use(0, *copy);
        copy->use(1, *copy);

        delete copy;
    }


    {
        std::cout << "\nTest NULL handling:" << std::endl;

        Character *me = new Character("me");
        me->equip(NULL); 
        me->use(0, *me); 
        me->unequip(10);

        delete me;
    }

    std::cout << "\nCleaning up any undeleted materias..." << std::endl;
    Character::cleanupMaterias();
    return 0;
}