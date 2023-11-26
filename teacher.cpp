#include "teacher.h"
#include"constant.h"
#include"auth.h"
#include"check.h"
#include"paper.h"
#include "Menu.h"
#include"date_sheet.h"
#include"Message.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
auth aa; check C; Menu mm; Message mg;
void teacher::log() {
	aa.log1();
	int user = aa.getUser();
	int passw = aa.getPassw();
	login(user, passw);
}
paper p; date_sheet d;
void teacher::login(int &user, int &pasw) {
	usr = user;

	if (C.check_teacher(user, pasw)) {
	teach_menu:
		//system("cls");
		std::cout << "=====\tWELCOME TEACHERS.....\t=====" << endl;
		std::cout << "Press:\n1. To Make paper \n";
		std::cout << "2. To Check paper \n";
		std::cout << "3. To View DateSheet\n";
		std::cout << "4. Q & A\n";
		std::cout << "5. Log out\n ";
		std::cout << "==>";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			//system("cls");
			p.make_paper();
			cout << "\nPress Any key to Go back : ";
			getchar();
			goto teach_menu;
			break;
		case 2:
			//system("cls");
			check_paper();
			cout << "\nPress Any key to Go back : ";
			getchar();
			goto teach_menu;
			break;
		case 3:
			//system("cls");
			d.view_datesheet();
			cout << "\nPress Any key to Go back : ";
			getchar();
			goto teach_menu;
			break;
		case 4:
			mg.ansStudent(user);
			cout << "\nPress Any key to Go back : ";
			getchar();
			goto teach_menu;
		case 5:
			mm.menu();
		default:
			std::cout << "INVALID CHOICE";
			break;
		}
	}
	else {
		std::cout << "Code No. Not found Ask Admin to register You or try again.\nThanks...";
	}
}

void teacher::check_paper() {
	string n, e, s; int r;
	ifstream ans_sht, ques_sht, file, ques;
	ofstream res;
	string a, b;
	string temp_subject;
	file.open("C:/SE/Examination_System/student.txt");
	res.open("C:/SE/Examination_System/result.txt", ios::app);
	if (!file) {
		std::cout << "Something went wrong Try again...";
	}
	string p = C.check_subject(usr);
	std::cout << "Check Paper of " << p << endl;
	std::cout << "Select Student To Check his/her Paper : " << endl;
	string check;
	while (getline(file, check))
	{
		istringstream iss(check);
		iss >> n >> e >> r;
		std::cout << "Name : " << n << ";  Roll Number : " << r << endl;
	}
	std::cout << "\nEnter Roll Number to Check : ";
	std::cin >> check_roll;
	int flag = 1;
	if (C.check_student(check_roll, check_roll)) {
		for (int i = 0; i < 5; i++) {
			if (p == subject[i]) {
				temp_subject = subject[i];
				ans_sht.open(Ans_sheet[i]);
				if (!ans_sht) {
					std::cout << "Something went wrong Try again...";
				}
				int j = 0;
				string tem;
				while (getline(ans_sht, a))
				{
					istringstream iss(a);
					string id, ans;
					iss >> id >> ans;
					if (stoi(id) == check_roll)
					{
						j++;
						std::cout << "Answer of No." << j << " Question : " << endl << ans << endl;
					}
				}
				std::cout << "Enter The Total marks for this student : ";
				std::cin >> obtained_marks;
				res << flag <<" " << temp_subject << " " << check_roll << " " << obtained_marks << endl;
			}
		}

	}
	else {
		std::cout << "please enter correct roll no. Press 1 to go back";
		char r;
		mm.menu();
	}
}