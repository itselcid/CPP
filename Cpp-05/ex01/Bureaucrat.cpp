#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(100) {
                           };
Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
{
    if (_grade < 1)
        throw high;
    else if (_grade > 150)
        throw low;
    else
        grade = _grade;
};
Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.name), grade(obj.grade)
{
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &obj)
{
    grade = obj.grade;
    return *this;
}
Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::get_name() const
{
    return name;
}
int Bureaucrat::get_grade() const
{
    return grade;
}
void Bureaucrat::increment_grade()
{
    if (grade - 1 < 1)
        throw high;
    else
        grade--;
}
void Bureaucrat::decrement_grade()
{
    if (grade + 1 > 150)
        throw low;
    else
        grade++;
}
void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.get_name() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->name << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &cout, const Bureaucrat &obj)
{
    cout << obj.get_name() << ", bureaucrat grade " << obj.get_grade() << " .";
    return cout;
}
