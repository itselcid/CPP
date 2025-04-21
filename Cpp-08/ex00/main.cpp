#include "easyfind.tpp"
#include <vector>

#include <list>
#include <iostream>

int main()
{
    std::vector<int> numbers;
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    int index = easyfind(numbers, 30);

    if (index != -1)
        std::cout << "Found value at index: " << index << std::endl;
    else
        std::cout << "Value not found." << std::endl;

    index = easyfind(numbers, 99);
    if (index == -1)
        std::cout << "Value 99 not found." << std::endl;

    return 0;
}