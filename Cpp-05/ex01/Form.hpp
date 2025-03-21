#pragma once

#include <iostream>
#include <string>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

class Bureaucrat;

class Form
{
    const std::string name;
    bool is_signed;
    const int sign_grade;
    const int sign_execute;
    GradeTooHighException high;
    GradeTooLowException low;

public:
    Form();
    Form(std::string _name, int _sign_grade, int _sign_execute);
    Form(const Form &obj);
    Form &operator=(const Form &obj);
    ~Form();

    std::string get_name() const;
    bool is_form_signed() const;
    int get_sign_grade() const;
    int get_sign_execute() const;
    void beSigned(Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &cout, const Form &obj);
