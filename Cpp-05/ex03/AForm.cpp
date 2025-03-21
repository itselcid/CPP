#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("default"), is_signed(false), sign_grade(100), sign_execute(10) {
                 };

AForm::AForm(std::string _name, int _sign_grade, int _sign_execute)
    : name(_name), is_signed(false), sign_grade(_sign_grade), sign_execute(_sign_execute)
{
    if (_sign_grade < 1 || _sign_execute < 1)
        throw high;
    else if (_sign_grade > 150 || _sign_execute > 150)
        throw low;
}

AForm::AForm(const AForm &obj)
    : name(obj.name), is_signed(obj.is_signed), sign_grade(obj.sign_grade), sign_execute(obj.sign_execute)
{
}

AForm &AForm::operator=(const AForm &obj)
{
    is_signed = obj.is_signed;
    return *this;
}
AForm::~AForm() {

};

std::string AForm::get_name() const
{
    return name;
}
bool AForm::is_form_signed() const
{
    return is_signed;
}
int AForm::get_sign_grade() const
{
    return sign_grade;
}
int AForm::get_sign_execute() const
{
    return sign_execute;
}
void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.get_grade() <= sign_grade)
        is_signed = true;
    else
        throw low;
}
std::ostream &operator<<(std::ostream &cout, const AForm &obj)
{
    cout << "AForm: " << obj.get_name() << ", Signed: " << (obj.is_form_signed() ? "Yes" : "No")
         << ", Sign Grade: " << obj.get_sign_grade() << ", Execute Grade: " << obj.get_sign_execute();
    return cout;
}