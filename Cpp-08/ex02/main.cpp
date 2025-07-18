#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{

    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top: " << mstack.top() << std::endl;
    
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    
    std::cout << "MutantStack contents:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "\nList contents:" << std::endl;
    std::list<int>::iterator lit = lst.begin();
    while ( lit != lst.end())
    {
        std::cout << *lit << std::endl;
        ++lit;
    }
    
    return 0;
}
