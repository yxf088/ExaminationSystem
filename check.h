#pragma once
#include<string>
#include<iostream>
using namespace std;
class check
{
private:
	string student_name;
	string student_email;
	string student_class;
	int student_rollNO;
	string teacher_name;
	string teacher_email; 
	string teacher_subject;
	int teacher_code;
	bool isfound = 0;
public:
	//bool check_class(string& classroom) ;
	bool check_student(int& roll, int& pass) ;
	bool check_teacher(int& roll, int& pass) ;
	bool check_answered(int& roll, int& ch);
	string check_subject(int& code) ;
	
};

