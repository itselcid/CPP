#ifndef MYREPLACER_HPP
#define MYREPLACER_HPP
#include <iostream>
#include <fstream>
#include <string>

class Myreplacer
{
    std::string s_toreplace;
    std::string s_tofind;

public:
    Myreplacer(const std::string s1, const std::string s2);
    std::string process_line(std::string &line);
};

#endif