#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
    IMateriaSource *src = new MateriaSource();

    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure);  
    

    std::cout << "\n2. Creating character 'me':" << std::endl;
    ICharacter *me = new Character("me");

    
    std::cout << "\n3. Creating and equipping materias:" << std::endl;
    AMateria *tmp;

    tmp = src->createMateria("ice"); 
    std::cout << "   Created materia of type: " << tmp->getType() << std::endl;
    me->equip(tmp); 
    std::cout << "   Equipped ice materia in slot 0" << std::endl;

    tmp = src->createMateria("cure");
    std::cout << "   Created materia of type: " << tmp->getType() << std::endl;
    me->equip(tmp); 
    std::cout << "   Equipped cure materia in slot 1" << std::endl;

    std::cout << "\n4. Testing invalid materia creation:" << std::endl;
    tmp = src->createMateria("unknown");
    if (tmp)
        std::cout << "   Created unknown materia (shouldn't happen)" << std::endl;
    else
        std::cout << "   Failed to create unknown materia type (expected)" << std::endl;

    std::cout << "\n5. Creating character 'bob':" << std::endl;
    ICharacter *bob = new Character("bob");

  
    std::cout << "\n6. Using materias on bob:" << std::endl;
    me->use(0, *bob); 
    me->use(1, *bob);

    std::cout << "\n7. Testing unequip functionality:" << std::endl;
    std::cout << "   Unequipping materia in slot 1" << std::endl;
    me->unequip(1); 
    std::cout << "   Trying to use the unequipped materia:" << std::endl;
    me->use(1, *bob); 


    std::cout << "\n8. Testing character copy:" << std::endl;
    Character *thirdChar = new Character("third");
    tmp = src->createMateria("ice");
    thirdChar->equip(tmp);

    std::cout << "   Creating a copy of 'third' character:" << std::endl;
    Character *charCopy = new Character(*thirdChar);
    std::cout << "   Copy name: " << charCopy->getName() << std::endl;
    std::cout << "   Using copy's materia:" << std::endl;
    charCopy->use(0, *bob);


    std::cout << "\n9. Cleaning up:" << std::endl;
    delete charCopy;
    delete thirdChar;
    delete bob;
    delete me;
    delete src;
    Character::cleanupMaterias();

    return 0;
}