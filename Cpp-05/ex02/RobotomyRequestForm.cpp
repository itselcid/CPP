#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot Form", 72, 45)
{
    target = " Default";
}
RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("Robot Form", 72, 45)
{
    target = _target;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
    target = obj.target;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    AForm::operator=(obj);
    target = obj.target;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {

};

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!is_form_signed())
        throw Form_not_signed;
    if (executor.get_grade() > get_sign_execute())
        throw low;

    srand(time(0));
    int randnum = rand() % 2;

    std::cout << " DRILLING NOISES  " << std::endl;
    if (randnum == 1)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << target << "." << std::endl;
}
