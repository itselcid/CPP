#include"Brain.hpp" 

Brain::Brain()
{
    std::cout <<"Brain Default constructor" << std::endl;
}
Brain::Brain(const Brain &obj)
{
   int i =0;
   while (i < 100)
   {
   ideas[i]=obj.ideas[i];
   i++;
   }
   
}

Brain &Brain::operator=(const Brain &obj)
{
    if(this != &obj)
    {
        int i =0;
        while (i < 100)
        {
        ideas[i]=obj.ideas[i];
        i++;
        }
    }
    return *this;
}

Brain::~Brain()
{
    std::cout <<"Brain Default destructor" << std::endl;
}