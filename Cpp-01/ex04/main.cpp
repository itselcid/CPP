#include <iostream>
#include <fstream>

void process_line(std::string line, std::string s1, std::string s2)
{
    size_t pos = 0;
    while ((pos = line.find(s1, pos)) != std::string::npos)
    {
        line.replace(pos, s1.length(), s2);
        pos += s2.length();
    }
    std::cout << line << std::endl;
}

int main(int ac, char **av)
{
    (void)av;
    if(ac!=4)
    {
        std::cout <<"Usage : <filename>  <S1>  <S2>" <<std::endl;
        return 1;
    }
    std::ifstream my_file(av[1]);
    if(!my_file)
    {
        std::cout << "Error: Unable to open the file." <<std::endl;
        return 1;
    }
    std::string line;
    while (!my_file.eof())
    {
        getline(my_file,line);
        process_line(line, av[2], av[3]);
    }
    
}