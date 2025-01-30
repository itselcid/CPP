#include "HarlFilter.hpp"

void HarlFilter::debug(void)
{
    std::cout << "[ DEBUG ]\n";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n";
    std::cout << "I really do!" << std::endl;
}

void HarlFilter::info(void)
{
    std::cout << "[ INFO ]\n";
    std::cout << "I cannot believe adding extra bacon costs more money.\n";
    std::cout << "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void HarlFilter::warning(void)
{
    std::cout << "[ WARNING ]\n";
    std::cout << "I think I deserve to have some extra bacon for free.\n";
    std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void HarlFilter::error(void)
{
    std::cout << "[ ERROR ]\n";
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
void HarlFilter::complain(std::string level)
{
    int level_num;
    
    if (level == "DEBUG")
        level_num = 0;
    else if (level == "INFO")
        level_num = 1;
    else if (level == "WARNING")
        level_num = 2;
    else if (level == "ERROR")
        level_num = 3;
    else
        level_num = 4;

      switch (level_num)
    {
        case 0:
            debug();
            info();
            warning();
            error();
            break;
        case 1:
            info();
            warning();
            error();
            break;
        case 2:
            warning();
            error();
            break;
        case 3:
            error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            break;
    }
}