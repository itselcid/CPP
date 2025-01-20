#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib> 

using std::cout;

using std::cin;
using std::string;
using std::setw;
using std::getline;

class PhoneBook{
	Contact contacts[8];
	int contact_index ;
	int total;
	public:
	PhoneBook();
	void add_contact(string f_name, string l_name,string n_name,string phone,string d_secret);
	void view_contacts();
	int check_string(string str);
	string truncat_str(string str);
};
	


#endif