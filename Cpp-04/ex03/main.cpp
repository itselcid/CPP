
#include"Character.hpp"
#include"MateriaSource.hpp"
#include"Ice.hpp"
#include"Cure.hpp"

int main()
{
    IMateriaSource *src = new MateriaSource();
    Ice *a = new Ice();
    src->learnMateria(a);
    src->learnMateria (a);
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
    Character::cleanupMaterias();
    return 0;
}