#include <iostream>
#include <fstream>
#include "funct.h"
#include "Admin.h"
#include "User.h"
#include <vector>
using namespace std;


//creates the line that replaces the old line in the .txt file
string toString(vector<User> users, int logged)
{
	string bal = to_string(users[logged].get());
	//creat bal2 because to string is adding too many decimals
	string bal2 = bal.substr(0, (bal.find('.')+3));
	string newLine = users[logged].username + " " + users[logged].password + " " + bal2;
	return newLine; 
}
//copies txt file to new but replaces the one line
void update(vector<User> users, int logged, string oldLine)
{
	string strReplace = oldLine;
	string strNew = toString(users, logged);
	cout << strNew;
	ifstream file("bankAccts.txt"); //File to read from
	ofstream temp("temp.txt"); //Temporary file

	string line;
	//goes through all lines and compares
	while (getline(file, line))
	{
		if (line == strReplace) {
			line = strNew;
		}
		//adds all lines but the new one replaces the old one
		temp << line << "\n";
	}
	//file.close();
	//temp.close();
	//remove("BankAccts.txt");
	//rename("temp.txt", "bankAccts.txt");
}

// subtracts from balance
void withDrawl(vector<User>& users, int logged, double sub)
{
	users[logged].set((users[logged].get()) - sub);
}
// adds to balance
void deposit(vector<User>& users, int logged, double add)
{
	users[logged].set((users[logged].get()) + add);
}

//not declared in funct.h because only used in other funcions under .cpp
void fillVec(vector<User>& users)
{
	//fills vector of objects to copare with 
	ifstream file("bankAccts.txt");
	string line;
	while (getline(file, line))
	{
		users.push_back(User(line));
	}
}
//creates accounts / lines in txt file
void signUp()
{
	string dummy; 
	ofstream file("bankAccts.txt", ios::app);
	string usrname; 
	string pssword; 
	string blance; 
	string chain; 
	cout << "What would you like your username to be? (no spaces)"; 
	cin >> usrname;
	cout << endl << "What would you like your password to be? (no spaces)";
	cin >> pssword; 
	cout << endl << "What is your starting balence? (no symbols)"; 
	cin >> blance; 
	cout << endl; 
	//combines them all to quickly insert to file
	chain = usrname + " " + pssword + " " + blance; 
	file << chain << endl; 
	cout << "Thank you for signing up! \n You can now access your data, aswell as deposit and withdraw!" << endl;
	// so the user can read messages before they are cleared by the next system cls
	cout << "Returning to main menu  (type \"ok\")" << endl; 
	cin >> dummy;
}
//logs in any user but also keep all of the data in one function for simplicity
int logIn()
{ 
	//fills vector of all users first to potntially log in
	vector<User> users;
	fillVec(users); 
	//variabel for stopping screens so interface can work
	string dummy;
	// the variables you are entering your data into to be cross checked
	string setUser; 
	string setPass; 
	//hard coded admin account so there is only one and app host/manager has access
	string adminUser = "PancakeLover12"; 
	string adminPass = "MadMax13";
	//to know what index of the vector is logged in as well as what row int the file to edit
	int loggedUser =-1;
	//log in process
	cout << "What is your username? "; 
	cin >> setUser; 
	cout << endl << "What is your password? ";
	cin >> setPass;
	cout << endl;
	//logs in admin 
	if (setUser == adminUser && setPass == adminPass)
	{
		Admin boss;
		cout << "Hello admin..." << endl << "Accessing data set..." << endl;
		//get function from admin returns data in kind of an array or spreadsheet
		boss.get();
		// so the user can read messages before they are cleared by the next system cls
		cout << "Tpye \"ok\" when finsihed recording info. " << endl; 
		cin >> dummy;
		return 0;
	}
	//checks to see if account exist
	for (int i = 0; i < users.size(); i++)
	{
		//getting exception errors so had to make these variables instead of directly comparing 
		string knownuser = users[i].username;
		string knownpass = users[i].password;
		if ((knownuser == setUser) && (knownpass == setPass))
		{
			system("CLS");
			cout << "Welcome " << users[i].username << "! \n";
			loggedUser = i;
		}
	}
	//detects if any username has been detected and will return to menu.
	if (loggedUser == -1)
	{
		cout << "Account not found returning to menu..." << endl << "Type \"OK\" to move forward" << endl;
		cin >> dummy;
		return 0; 
	}
	//another menu to choose from
	int option2; 
	cout << "What would you like to do today? " << endl << "(1) View balance" << endl << "(2) Deposit" << endl << "(3) Withdraw" << endl;
	cin >> option2; 
	//displays balance
	if (option2 == 1)
	{
		cout << "Your balance is: $" << users[loggedUser].get() << endl;
	}
	//ask for num to deposit then calls func to add it 
	if (option2 == 2)
	{
		//creates a line now so we can later detect it to replace with new line in txt
		string oldLine = toString(users, loggedUser);
		cout << "How much would you like to deposit? (no symbols)";
		double dAMT;
		cin >> dAMT;
		deposit(users, loggedUser, dAMT);
		cout << "You deposited $" << dAMT << ". Your new balance is $" << users[loggedUser].get() << ".";
		update(users, loggedUser, oldLine);
	}
	//ask for amount to remove
	if (option2 == 3)
	{
		//creates a line now so we can later detect it to replace with new line in txt
		string oldLine = toString(users, loggedUser);
		cout << "How much would you like to withdrawl? (no symbols)";
		double wAMT; 
		cin >> wAMT; 
		withDrawl(users, loggedUser, wAMT);
		cout << "You withdrawled $" << wAMT << ". Your new balance is $" << users[loggedUser].get() << "." << endl;
		update(users, loggedUser, oldLine);
	}
	cout << "Thank you for interacting with your account today." << endl << "Type \"OK\" to return to the main menu.";
	cin >> dummy;
	return 0;
}
