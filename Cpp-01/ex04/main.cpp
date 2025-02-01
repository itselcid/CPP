#include "Myreplacer.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4 || !av[1][0] || !av[2][0] || !av[3][0])
    {
        std::cout << "Usage: <filename> <string_to_find> <string_to_replace>" << std::endl;
        return 1;
    }

    std::ifstream in_file(av[1]);
    if (!in_file)
    {
        std::cout << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    std::string outfilename = std::string(av[1]) + ".replace";
    std::ofstream out_file(outfilename.c_str());

    if (!out_file)
    {
        std::cout << "Error: Unable to open the file." << std::endl;
        return 1;
    }
    Myreplacer replacer(av[2], av[3]);
    std::string line;
    while (std::getline(in_file, line))
    {
        out_file << replacer.process_line(line);
        if (!in_file.eof())
            out_file << std::endl;
    }
    in_file.close();
    out_file.close();
}