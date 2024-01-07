#include "Admin.h"
#include <iostream>

#include<fstream>
using namespace std;
// admin class has method that shows data in a sort of spreadsheet.
void Admin::get()
{
	ifstream file("bankAccts.txt");
	string input; 
	int i = 0; 
	while (file >> input)
	{
		i++;
			cout << input << " ";
			if (i % 3 == 0)
			{
				cout << endl;
			}
	}
}