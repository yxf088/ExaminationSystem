#include "check.h"
#include"constant.h"
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;

bool check::check_student(int& roll, int& pass) {
	fstream file;
	file.open("C:/SE/Examination_System/student.txt", ios::in);
	if (!file) {
		cout << "Something went wrong Try again...";

	}
	while (!file.eof()) {
		file >> student_name >> student_email >> student_rollNO;
		if (roll == student_rollNO && pass == student_rollNO) {
			isfound = 1;
			break;
		}

	}
	return isfound;
}
bool check::check_teacher(int& roll, int& pass) {
	fstream file;
	file.open("C:/SE/Examination_System/teacher.txt", ios::in);
	if (!file) {
		cout << "Something went wrong Try again...";
	}
	while (!file.eof()) {
		file >> teacher_name >> teacher_email >> teacher_subject >> teacher_code;
		if (roll == teacher_code && pass == teacher_code) {
			isfound = 1;
			break;
		}
	}
	return isfound;
}

string check::check_subject(int& code) {
	string sub;
	fstream file;
	file.open("C:/SE/Examination_System/teacher.txt", ios::in);
	if (!file) {
		cout << "Something went wrong Try again...";
	}
	while (!file.eof()) {
		file >> teacher_name >> teacher_email >> teacher_subject >> teacher_code;
		if (code == teacher_code) {
			sub = teacher_subject;
			break;
		}
	}
	return sub;
}

bool check::check_answered(int& roll,int &ch)
{
	string sub, grade;
	int rollnumber,flag;
	fstream file;
	file.open("C:/SE/Examination_System/result.txt", ios::in);
	if (!file) {
		cout << "Something went wrong Try again...";

	}
	int found = 0;
	while (!file.eof()) {
		file >> flag >> sub >> rollnumber >> grade;
		if (flag) {
			if (roll == rollnumber && subject[ch - 1] == sub) {
				found = 1;
				break;
			}
		}
	}
	return found;
}