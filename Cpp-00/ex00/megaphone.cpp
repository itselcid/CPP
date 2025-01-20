#include <iostream>

using std::cout;
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
        return 0;
    }
    else
    {
        int i=1;

        while(i<argc)
        {
            int j = 0;
            while (argv[i][j])
            {
                cout << char(toupper(argv[i][j]));
                j++;
            }
            i++;
        }
        cout <<"\n";
    }
}