#pragma once

#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

#include "FormNotSignedException.hpp"
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat;

class AForm
{
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int sign_execute;

public:
    AForm();
    AForm(std::string _name, int _sign_grade, int _sign_execute);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
    ~AForm();
    FormNotSignedException Form_not_signed;
    GradeTooHighException high;
    GradeTooLowException low;
    std::string get_name() const;
    bool is_form_signed() const;
    int get_sign_grade() const;
    int get_sign_execute() const;
    void beSigned(Bureaucrat &obj);

    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &cout, AForm &obj);
