#include"Contact.hpp"

void Contact::set_contact(string f_name, string l_name,string n_name,string phone, string d_secret)
{
first_name =f_name;
last_name = l_name;
nick_name = n_name;
phone_number = phone;
darkest_secret = d_secret;

};
string Contact::get_first_name()
{
	return first_name;
}
string Contact::get_last_name()
{
	return last_name;
}
string Contact::get_nick_name()
{
	return nick_name;
}
string Contact::get_phone()
{
	return phone_number;
}
string Contact::get_darkest_secret()
{
	return darkest_secret;
}