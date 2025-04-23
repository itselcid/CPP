#include "Span.hpp"

#include <ctime>

int main()
{

    Span bigSpan = Span(10000);

    try
    {
        std::cout << "Adding individual numbers...\n";
        bigSpan.addNumber(42);
        bigSpan.addNumber(-10);
        bigSpan.addNumber(100);
        std::cout << "Successfully added three numbers individually\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::vector<int> manyNumbers;

    std::srand(std::time(NULL));

    std::cout << "Generating 500 random numbers...\n";
    for (int i = 0; i < 500; i++)
    {
        manyNumbers.push_back(std::rand() % 10000);
    }

    try
    {
        std::cout << "Adding 500 numbers at once using addNumbers...\n";
        bigSpan.addNumbers(manyNumbers.begin(), manyNumbers.end());
        std::cout << "Successfully added all numbers\n";
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "Trying to add more numbers than capacity...\n";
        std::vector<int> tooManyNumbers(10000, 1); 
        Span smallSpan(10);
        smallSpan.addNumbers(tooManyNumbers.begin(), tooManyNumbers.end());
    }
    catch (const std::exception &e)
    {
        std::cout << "Expected error: " << e.what() << std::endl;
    }

    return 0;
}