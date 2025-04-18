#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
    std::cout << "I really do!"<< std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
              
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n";
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
              
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;

}

void Harl::complain(std::string level)
{
    void (Harl::*farray[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int found = 0;
    int i = 0;
    while (i < 4)
    {
        if (level == levels[i])
        {
            (this->*farray[i])();
            found = 1;
        }
    
        i++;
    }
    if (found == 0)
        std::cout << "Invalid level\n";
}