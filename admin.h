#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class admin
{
private:
	//admin credentials: 
	const string admin_username = "admin";
	const string admin_password = "123";

	//for File IO
	string student_name;
	string student_email;
	string student_class;
	int student_rollNO;

	int choice;
	bool isFound = 0;
	string Class;
	int ret = 0;

	string teacher_name;
	string teacher_email;
	int teach_Code;

public:
	void make_datesheet() ;
	void add_student() ;
	void add_teacher() ;
	void log() ;
	void login(string& user, string &pass);
	void delete_studentaccount();
	void delete_teacheraccount();
};

