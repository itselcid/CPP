#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    string command;
    string f_name;
    string l_name;
    string n_name;
    string phone;
    string d_secret;

    while ( 1)
    {
		cout << "Enter your command: ";
		getline(cin, command);
        if (cin.eof())
            break;

        if (command == "ADD")
        {
            cout << "Enter first name: ";
            getline(cin, f_name);
            cout << "Enter last name: ";
            getline(cin, l_name);
            cout << "Enter nick name: ";
            getline(cin, n_name);
            cout << "Enter phone number: ";
            getline(cin, phone);
            cout << "Enter darkest secret: ";
            getline(cin, d_secret);
            phonebook.add_contact(f_name, l_name, n_name, phone, d_secret);
        }
        else if (command == "SEARCH")
        {
         phonebook.view_contacts();
        }
        else if (command == "EXIT")
        {
            break;
        }
        else
        {
            cout << "Your command is invalid please try again(ADD, SEARCH, EXIT) \n"; ;
        }
    }
	cout << "\n";
    return 0;
}