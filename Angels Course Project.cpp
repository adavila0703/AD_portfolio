// ---------------------------------------------------------------
// Programming Assignment: Course Project
// Developer:Angel Davila
// Course: CIS170
// Date Written:11/9/2017
// Purpose:iNVENTORY SYSTEM - COURSE PROJECT
// ---------------------------------------------------------------
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//MAIN MENU
void menu()
{
	string input;

	const int SIZE = 4;
	string menuoptions[SIZE] = { "Enter Item", "Inventory", "Adjustment", "Exit" };

	bool menu = false;
	while (menu == false)
	{


		cout << "\nMain menu" << endl;
		cout << "______________" << endl;
		cout << "1. Enter Item" << endl;
		cout << "2. Inventory" << endl;
		cout << "3. Adjustment" << endl;
		cout << "4. Exit" << endl;
		cin >> input;
		int choice1 = 0;
		switch (choice1)
		{
		case 1:
			cout << "\nEnter Item Menu" << endl;
			cout << "______________" << endl;
			cout << "welcome" << endl;
			// rest of code here
			break;
		case 2:
			cout << "\nInventory Menu" << endl;
			cout << "______________" << endl;
			cout << "Hi" << endl;
			// rest of code here
			break;
		case 3:
			cout << "\nMain menu" << endl;
			cout << "______________" << endl;
			cout << "Stock adjustment" << endl;
			// rest of code here
			break;
		case 4:
			cout << "\nGood Bye." << endl;
			menu = false;
			break;
		default:
			cout << "Not a Valid Choice. \n";
			cout << "Choose again.\n";
			break;
		}

	}
}


//Register question
void registration()
{

	bool registered = false;
	string reg, name, pass, signinput, signinput2;

	ofstream users, passwords;

	users.open("users.csv", ios::app);
	passwords.open("passwords.csv", ios::app);


	while (registered == false)
	{
		cout << "Thank you." << endl;
		cout << "\nPlease enter your desired name and password.\n";
		cout << "Username:";

		cin >> name;


		//CREATING A USER

		users << name << endl;
		users.close();

		cout << "Password:";

		cin >> pass;
		passwords << pass << endl;
		passwords.close();

		cout << "\nWelcome " << name;
		cout << " please sign in.\n";

		registered = true;
	}
}

//SIGNIN FUNCTION
void signin()
{
	int line = 1000;
	bool signin = false;
	string name, pass, signinput, signinput2;

	ifstream passwords("passwords.csv");
	ifstream users("users.csv");

	users.open("users.csv", ios::app);
	passwords.open("passwords.csv", ios::app);

	while (getline(users, name, '\n') && (getline(passwords, pass, '\n')))
	{
		cout << "\nUsername:";
		cin >> signinput;
		cout << "\nPassword:";
		cin >> signinput2;
		if (name == signinput && pass == signinput2)
		{
			cout << "Success!" << endl;
			menu();
		}
		else
		{
			cout << "Failed!" << endl;
		}
	}

}

int main()
{
	/* ios are open for output operations. Will not override. Creates a database

		("database", ios::out | ios::app)

		ios::app -> appends data
	*/
	// DATABASE
	ofstream users, passwords;
	//users csv

	users.open("users.csv", ios::app);
	passwords.open("passwords.csv", ios::app);

	string reg;
	bool first = false;

	//main loop
	while (first = true)
	{
		cout << "Hello, are you registered? y/n" << endl;
		cin >> reg;
		if (reg == "y")
		{
			signin();
			menu();
			first = true;
		}
		else if (reg == "n")
		{
			registration();
			signin();
			first = true;
		}
		else
		{
			continue;
		}
	}
	cout << "\n\n";
	system("pause");
}
