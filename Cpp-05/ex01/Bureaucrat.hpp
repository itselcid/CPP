#pragma once

#include <string>
#include <iostream>

#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"
#include "Form.hpp"

class Bureaucrat
{
    const std::string name;
    int grade;
    GradeTooHighException high;
    GradeTooLowException low;

public:
    Bureaucrat();
    Bureaucrat(std::string _name, int _grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat &operator=(const Bureaucrat &obj);
    ~Bureaucrat();

    std::string get_name();
    int get_grade();
    void increment_grade();
    void decrement_grade();
    void signForm(Form &from);
};

std::ostream &operator<<(std::ostream &cout, Bureaucrat &obj);