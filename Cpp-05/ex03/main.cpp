#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern stageier;
    AForm *form = stageier.makeForm("shrubbery creation", "sdf");
    delete form;
    return 0;
}