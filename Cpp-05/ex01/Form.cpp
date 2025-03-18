#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("default"), is_signed(false), sign_grade(100), sign_execute(10) {
               };

Form::Form(std::string _name, int _sign_grade, int _sign_execute)
    : name(_name), is_signed(false), sign_grade(_sign_grade), sign_execute(_sign_execute)
{
    if (_sign_grade < 1 || _sign_execute < 1)
        throw high;
    else if (_sign_grade > 150 || _sign_execute > 150)
        throw low;
}

Form::Form(const Form &obj)
    : name(obj.name), is_signed(obj.is_signed), sign_grade(obj.sign_grade), sign_execute(obj.sign_execute)
{
}

Form &Form::operator=(const Form &obj)
{
    is_signed = obj.is_signed;
    return *this;
}
Form::~Form() {

};

std::string Form::get_name()
{
    return name;
}
bool Form::is_form_signed()
{
    return is_signed;
}
int Form::get_sign_grade()
{
    return sign_grade;
}
int Form::get_sign_execute()
{
    return sign_execute;
}
void Form::beSigned(Bureaucrat &obj)
{
    if (obj.get_grade() <= sign_grade)
        is_signed = true;
    else
        throw low; 

}
std::ostream &operator<<(std::ostream &cout, Form &obj){
    cout << "Form: " << obj.get_name() << ", Signed: " << (obj.is_form_signed() ? "Yes" : "No") 
         << ", Sign Grade: " << obj.get_sign_grade() << ", Execute Grade: " << obj.get_sign_execute();
    return cout;
}