#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
using std::string;

class Contact{

	string first_name;
	string last_name;
	string nick_name;
	string phone_number;
	string darkest_secret;
	public:

	void set_contact(string f_name, string l_name,string n_name,string phone,string d_secret);
	string get_first_name();
	string get_last_name();
	string get_nick_name();
	string get_phone();
	string get_darkest_secret();

};

#endif
