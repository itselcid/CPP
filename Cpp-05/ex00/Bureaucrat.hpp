#pragma once

#include <string>
#include <iostream>
#include "GradeTooHighException.hpp"
#include "GradeTooLowException.hpp"

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

    std::string get_name() const;
    int get_grade() const;
    void increment_grade();
    void decrement_grade();
};

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &obj);