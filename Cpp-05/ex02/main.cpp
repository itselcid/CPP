#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try {
        ShrubberyCreationForm hh("target");
        Bureaucrat test("bureaucrat", 148);
        
        test.signForm(hh);
        
        hh.execute(test);
        
    
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}