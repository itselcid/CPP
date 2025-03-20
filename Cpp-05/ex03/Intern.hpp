
#pragma once 

 #include"AForm.hpp"
 #include "ShrubberyCreationForm.hpp"
 #include "PresidentialPardonForm.hpp"
 #include "RobotomyRequestForm.hpp"
 
class Intern{

    public:
    Intern();
    Intern(const Intern &obj);
    Intern &operator=(const Intern &obj);
    ~Intern();
    AForm *makeForm(std::string form_name, std::string target);
    
};