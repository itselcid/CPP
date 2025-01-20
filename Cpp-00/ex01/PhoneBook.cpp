#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	contact_index = 0;
	total = 0;
}

int PhoneBook::check_string(string str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if (!isprint(str[i]))
		{
			return 0;
		}
		i++;
	}
	return 1;
}

void PhoneBook::add_contact(string f_name, string l_name, string n_name, string phone, string d_secret)
{
	if (f_name.length() == 0 || l_name.length() == 0 || n_name.length() == 0 || phone.length() == 0 || d_secret.length() == 0)
	{
		cout << "Error\nRequired fields cannot be empty \n";
		return;
	}
	if (!check_string(f_name) || !check_string(l_name) || !check_string(n_name) ||
		!check_string(phone) || !check_string(d_secret))
	{
		cout << "Error\nInvalid characters\n";
		return;
	}
	contacts[contact_index].set_contact(f_name, l_name, n_name, phone, d_secret);
	contact_index = (contact_index + 1) % 8;
	if (total < 8)
		total++;
	cout << "Contact added successfully \n";
}
string PhoneBook::truncat_str(string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::view_contacts()
{
	if (total == 0)
	{
		cout << "Phonebook is empty\n";
		return;
	}

	int i = 0;
	cout << setw(10) << "Index" << "|"
		 << setw(10) << "First Name" << "|"
		 << setw(10) << "Last Name" << "|"
		 << setw(10) << "Nickname" << "\n";

	cout << "---------------------------------------------\n";
	while (i < total)
	{
		cout << setw(10) << i << "|"
			 << setw(10) << truncat_str(contacts[i].get_first_name()) << "|"
			 << setw(10) << truncat_str(contacts[i].get_last_name()) << "|"
			 << setw(10) << truncat_str(contacts[i].get_nick_name()) << "\n";
		i++;
	}
	cout << "Enter the index of the contact you want to see its full infos: ";
	string input;
	getline(cin, input);

	if (input.length() == 0)
	{
		cout << "Invalid index\n";
		return;
	}
	size_t j = 0;
	while (j < input.length())
	{
		if (!isdigit(input[j]))
		{
			cout << "Invalid index\n";
			return;
		}
		j++;
	}
	int index = atoi(input.c_str());
	if (index < 0 || index >= total)
	{
		cout << "Index out of range\n";
		return;
	}

	cout << "First Name: " << contacts[index].get_first_name() << "\n";
	cout << "Last Name: " << contacts[index].get_last_name() << "\n";
	cout << "Nick Name: " << contacts[index].get_nick_name() << "\n";
	cout << "Phone Number: " << contacts[index].get_phone() << "\n";
	cout << "Darkest Secret: " << contacts[index].get_darkest_secret() << "\n";
}