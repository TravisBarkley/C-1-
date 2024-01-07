#include <iostream>
#include <fstream>
#include "funct.h"
#include "Admin.h"
#include "User.h"
#include <vector>
#include <string>
using namespace std; 

int main() 
{
	int option;
	int i = 0; 
	//menu of options presented that eill continue to show up until you choose to exit
	while (i < 1)
	{
		cout << "----------------------------------" << endl << "Welcome to the Barkley Banking App" << endl;
		cout << "(1) Sign up" << endl << "(2) Log in" << endl << "(3) Exit App" << endl << "Choose an option (1, 2 or 3): ";
		cin >> option;
		//calls sign up method and clears window for looks
		if (option == 1)
		{
			system("CLS");
			signUp();
			system("CLS");
		}
		//calls log in  method and clears window for looks
		if (option == 2)
		{
			system("CLS");
			logIn();
			system("CLS");
		}
		// exits program
		if (option == 3)
		{
			cout << "Thank you, Have a nice day!" << endl;
			return 0; 
		}
	}
}