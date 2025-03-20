#include "Intern.hpp"

Intern::Intern()
{
}
Intern::~Intern()
{
}
Intern::Intern(const Intern &obj)
{
}
Intern &Intern::operator=(const Intern &obj)
{
    return *this;
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
    std::string form_names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};

    AForm *form_types[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)};

    int i = 0;
    while (i < 3)
    {
        if (form_name == form_names[i])
        {
            std::cout << "Intern creates " << form_types[i]->get_name() << std::endl;
            int j = 0;
            while (j < 3)
            {
                if (j != i)
                    delete form_types[j];
                j++;
            }
            return form_types[i];
        }

        i++;
    }

    i = 0;
    while (i < 3)
    {
        delete form_types[i];
        i++;
    }
    std::cout << " the Form name passed  doesn’t exist " << std::endl;
    return NULL;
}