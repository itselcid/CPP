#pragma once

#include <string>
#include <iostream>

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "FormNotSignedException.hpp"

class Bureaucrat;

class AForm
{
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int sign_execute;
    GradeTooHighException high;
    GradeTooLowException low;
    FormNotSignedException form_not_signed;

public:
    AForm();
    AForm(std::string _name, int _sign_grade, int _sign_execute);
    AForm(const AForm &obj);
    AForm &operator=(const AForm &obj);
    virtual ~AForm();

    std::string get_name() const;
    bool is_form_signed() const;
    int get_sign_grade() const;
    int get_sign_execute() const;
    void beSigned(Bureaucrat &obj);
    virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &cout, const AForm &obj);
