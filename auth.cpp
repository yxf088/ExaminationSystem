#include "auth.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;


void auth::log() {
	cout << "Enter Username  : "; cin >> username;
	cout << "Enter Password  : "; cin >> pass;
}
void auth::log1() {
	cout << "Enter Username  : "; cin >> user;
	cout << "Enter Password  : "; cin >> passw;
}
int auth::getUser()
{
	return user;
}
int auth::getPassw()
{
	return passw;
}
string auth::getAdminUsername()
{
	return username;
}
string auth::getAdminPassword()
{
	return pass;
}