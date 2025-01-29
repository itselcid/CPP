#include "Myreplacer.hpp"

Myreplacer::Myreplacer(const std::string s1, const std::string  s2) 
{
    s_tofind = s1;
    s_toreplace = s2;
};

std::string Myreplacer::process_line(std::string& line)
{
    std::string result;
    size_t start_pos = 0;
    size_t pos=0;
    while((pos =line.find(s_tofind, pos)) != std::string::npos)
    {
        result += line.substr(start_pos, pos - start_pos);
        result += s_toreplace;
        start_pos = pos + s_tofind.length();
    }
    result += line.substr(start_pos);
    return result;
}