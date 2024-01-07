#include <iostream>
#include <fstream>
#include "funct.h"
#include "Admin.h"
#include "User.h"
#include <vector>
#include <string>
using namespace std; 
//get method
	double User::get()
	{
		return balance; 
	}
	//setter for private balance
	void User::set(double x)
	{
		balance = x; 
	}
	//default constructor?! i was getting errors that I didnt have one because of the other constructor
	User::User()
	{
		username = " ";
		password = " ";
		balance = 0;
	}
	//construcotr that takes a line of .txt and fills the data members
	User::User(string line)
	{
		int space1; 
		int space2;
		username = line.substr(0, line.find(' '));
		//cout << username << endl;
		space1 = line.find(' ') + 1; 
		space2 = line.find(' ', space1);
		int length = (space2 - space1); 
		password = line.substr(space1, length); 
		//cout << password << endl; 
		set(stod(line.substr(space2)));
		
		
	}
