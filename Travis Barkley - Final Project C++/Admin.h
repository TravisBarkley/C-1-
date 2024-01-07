
#include "User.h"
#include <iostream>
#include <fstream>
#include <string>
//header for admin sub class
class Admin :
    public User
{
public:
    void get();
};

