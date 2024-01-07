#ifndef USER
#define USER
#include <iostream>
#include <string>
//user header file 
using namespace std;
class User
{
public:
	string username;
	string password;
	double get();
	void set(double x);
	User(string line);
	User();
private:
	double balance;
};
#endif

