#include <iostream>
#include <string> 
#include "Array.hpp"


#include "Array.tpp"

int main( void )
{
    
    Array<std::string> stringArray(10);
    Array<std::string> otherStringArray;

    stringArray[0] = "Hi";
    stringArray[1] = "Hello";
    stringArray[2] = "its";
    stringArray[3] = "me";
    stringArray[4] = "omar";

    std::cout << "stringArray.size() = " << stringArray.size() << std::endl; 

    otherStringArray = stringArray; 
    otherStringArray[3] = "I'm good, how about you?"; 

    std::cout << "--- Original stringArray ---" << std::endl;
    std::cout << stringArray[0] << std::endl;
    std::cout << stringArray[1] << std::endl;
    std::cout << stringArray[2] << std::endl;
    std::cout << stringArray[3] << std::endl; 
    std::cout << stringArray[4] << std::endl;

    std::cout << "\n--- Modified otherStringArray ---" << std::endl;
    std::cout << otherStringArray[3] << std::endl;

    std::cout << std::endl;

    std::cout << "--- Testing Array<int> ---" << std::endl;
    Array<int> intArray(5);
    Array<int> otherIntArray;

    intArray[0] = 10;
    intArray[1] = 20;
    intArray[2] = 30;
    intArray[3] = 40;
    intArray[4] = 50;

    std::cout << "intArray.size() = " << intArray.size() << std::endl; 

    otherIntArray = intArray; 
    otherIntArray[1] = 25;    

    std::cout << "Original intArray[0]: " << intArray[0] << std::endl; 
    std::cout << "Original intArray[1]: " << intArray[1] << std::endl; 
     std::cout << "otherIntArray[0]: " << otherIntArray[0] << std::endl;
    std::cout << "Modified otherIntArray[1]: " << otherIntArray[1] << std::endl;
   
    std::cout << std::endl;

    std::cout << "--- Testing exceptions ---" << std::endl;
    try
    {
        std::cout << "Accessing stringArray[59]: ";
        std::cout << stringArray[59] << std::endl; 
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        std::cout << "Accessing intArray[-3]: ";
        std::cout << intArray[-3] << std::endl; 
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;


    return 0;
}