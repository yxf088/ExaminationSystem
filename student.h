#pragma once

#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class student
{
private:
	int valid;
	int choice;
	char answer[256];
	int ret;
	int flag;

public:
	int log() ;
	void give_paper() ;
	void login(int &user, int& pasw) ;
	void result() ;
	void view_paperAns(int &user);
};

