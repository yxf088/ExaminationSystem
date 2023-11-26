#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class auth
{
protected:
	string username;
	string pass;
	int user, passw;
public:
	void log() ;
	void log1() ;
	int getUser();
	int getPassw();
	string getAdminUsername();
	string getAdminPassword();
};

