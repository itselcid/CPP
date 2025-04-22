#include"iter.hpp"
#include"iostream"

void func(int i)
{
    std::cout<<i<<std::endl;
}

int main()
{
    int array[]={1,2,3,4,5};
    ::iter(array,3,func);

}