#include "admin.h"
#include "date_sheet.h"
#include "Menu.h"
#include"auth.h"
#include"constant.h"
#include<vector>
#include<iostream>
using namespace std;

date_sheet Dd; Menu Mm;
void admin::make_datesheet()
{
	int date = Dd.getdate();
	int month = Dd.getmonth();
	int year = Dd.getyear();
	int starting_time = Dd.get_st();
	int ending_time = Dd.get_et();
	do {
		//system("cls");
		cout << "\t\t\t----------Welcome admin----------- \n\n";
		cout << "\t\tMake Date sheet \n";
		cout << "Enter the class Name :";
		std::cin >> Class;

		ofstream date_sheet;
		date_sheet.open("C:/SE/Examination_System/date_sheet.txt");
		if (!date_sheet) {
			cout << "File Not Found or permission denied.";
		}
		for (int i = 0; i < 5; i++) {
			cout << "For " << subject[i] << " : " << endl;
			cout << "Enter Date (DD-MM-YYYY) :\n";
			cout << "Enter Date : ";
			std::cin >> date;
			cout << "Enter Month: ";
			std::cin >> month;
			cout << "Enter Year: ";
			std::cin >> year;
			cout << "Enter Time" << endl;
			cout << "Enter Starting time : ";
			std::cin >> starting_time;
			cout << "Enter Ending Time : ";
			std::cin >> ending_time;

			date_sheet << subject[i] << " " << date << " " << month << " " << year << " " << starting_time << " " << ending_time << " " << endl;
		}
		return;
		std::cin >> ret;
		
	} while (ret == 1);
}

void admin::add_student() {
	do {
		cout << "\t\tAdd Students \n";
		cout << "Enter Student Name: ";
		std::cin >> student_name;
		cout << "Enter student email: ";
		std::cin >> student_email;
		cout << "Enter student Roll No.: ";
		std::cin >> student_rollNO;
		ofstream Add_student;
		Add_student.open("C:/SE/Examination_System/student.txt", ios::app);
		if (!Add_student) {
			cout << "File Not Found or permission denied.";
		}
		else {
			Add_student << student_name << " " << student_email << " " << student_rollNO << " " << endl;
		}
		Add_student.close();
		cout << "Enter 1 to add another student else back:  ";
		std::cin >> ret;
		if (ret != 1) return;
	} while (ret == 1);
}

void admin::add_teacher() {
	do {
		//system("cls");
		cout << "Enter Teacher Name: ";
		std::cin >> teacher_name;
		cout << "Enter Teacher email: ";
		std::cin >> teacher_email;
		cout << "Enter Teacher Subect: " << endl;;
		for (int i = 0; i < 5; i++) {
			cout << "Press " << i << " For " << subject[i] << endl;
		}
		cout<<"==>";
		int ch;
		std::cin >> ch;
		cout << "Enter Teacher Code : ";
		std::cin >> teach_Code;
		ofstream teacher;
		teacher.open("C:/SE/Examination_System/teacher.txt", ios::app);
		if (!teacher) {
			cout << "File Not Found Something went wrong Try again.";
		}
		else {
			teacher << teacher_name << " " << teacher_email << " " << subject[ch] << " " << teach_Code << " " << endl;
		}
		teacher.close();
		cout << "Enter 1 to add another teacher else back";
		std::cin >> ret;
	} while (ret == 1);
}

auth aaaa;
void admin::log() {
	aaaa.log();
	string username = aaaa.getAdminUsername();
	string pass = aaaa.getAdminPassword();
	login(username, pass);
}

void admin::delete_studentaccount()
{
	string studentRollNo;
	cout << "Enter Roll No. of student to delete: ";
	cin >> studentRollNo;
	std::ifstream inputFile("C:/SE/Examination_System/student.txt");
	std::vector<std::string> lines;
	std::string line;
	// 读取文件内容到 vector 中
	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();
	bool found = false;
	std::ofstream outputFile("C:/SE/Examination_System/student.txt");
	if (!outputFile) {
		std::cout << "File Not Found or permission denied." << std::endl;
		return;
	}
	// 查找并删除带有给定学号的学生信息
	for (const auto& l : lines) {
		std::istringstream iss(l);
		std::string name, email, rollNo;
		if (iss >> name >> email  >> rollNo) {
			if (rollNo != studentRollNo) {
				outputFile << l << std::endl;
			}
			else {
				found = true;
			}
		}
	}
	outputFile.close();
	if (found) {
		std::cout << "Student with Roll No. " << studentRollNo << " deleted successfully." << std::endl;
	}
	else {
		std::cout << "Student with Roll No. " << studentRollNo << " not found." << std::endl;
	}
}

void admin::delete_teacheraccount()
{
	string teacherCode;
	cout << "Enter Code of teacher to delete: ";
	cin >> teacherCode;

	std::ifstream inputFile("C:/SE/Examination_System/teacher.txt");
	std::vector<std::string> lines;
	std::string line;

	// 读取文件内容到 vector 中
	while (std::getline(inputFile, line)) {
		lines.push_back(line);
	}
	inputFile.close();
	bool found = false;
	std::ofstream outputFile("C:/SE/Examination_System/teacher.txt");
	if (!outputFile) {
		std::cout << "File Not Found or permission denied." << std::endl;
		return;
	}
	// 查找并删除带有给定教师代码的教师信息
	for (const auto& l : lines) {
		std::istringstream iss(l);
		std::string name, email, subject, code;

		if (iss >> name >> email >> subject >> code) {
			if (code != teacherCode) {
				outputFile << l << std::endl;
			}
			else {
				found = true;
			}
		}
	}

	outputFile.close();

	if (found) {
		std::cout << "Teacher with Code " << teacherCode << " deleted successfully." << std::endl;
	}
	else {
		std::cout << "Teacher with Code " << teacherCode << " not found." << std::endl;
	}
}

void admin::login(string& user, string& pass) {
	int ret = 0;
	do {
		//system("cls");
		if (user == admin_username && pass == admin_password) {
			cout << "Press\n1.For Add Student \n";
			cout << "2.For Add Teacher \n";
			cout << "3.To Make Date_Sheet \n";
			cout << "4.Delete Student\n";
			cout << "5.Delete Teacher\n";
			cout << "6.Log out\n";
			cout << "==>";
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				add_student();
				login(user, pass);
				break;
			}
			case 2:
				add_teacher();
				login(user, pass);
				break;
			case 3:
				make_datesheet();
				login(user, pass);
				break;
			case 4:
				delete_studentaccount();
				login(user, pass);
				break;
			case 5:
				delete_teacheraccount();
				login(user, pass);
				break;
			case 6:
				Mm.menu();
			default:
				cout << "Invalid Choice Press 0 to Try Again else Exit..";
				cin >> ret;
				break;
			}
		}
		else {
			cout << "Please Retry...\n";
			log();
		}
	} while (ret == 0);
}