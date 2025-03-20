#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


int main()
{
    try {
       
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Bender");
        PresidentialPardonForm pardon("prisoner");
        
        
        Bureaucrat intern("Intern", 140);        
        Bureaucrat officer("Officer", 50);       
        Bureaucrat executive("Executive", 5);   
        
        std::cout << "\n--- SHRUBBERY TESTS ---\n";
        intern.signForm(shrub);
        intern.executeForm(shrub);  
        officer.executeForm(shrub); 
        

        std::cout << "\n--- ROBOTOMY TESTS ---\n";
        intern.signForm(robot);   
        officer.signForm(robot);
        officer.executeForm(robot); 
        
        std::cout << "\n--- PRESIDENTIAL TESTS ---\n";
        executive.signForm(pardon);
        executive.executeForm(pardon);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}