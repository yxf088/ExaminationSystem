#include "student.h"
#include"constant.h"
#include"auth.h"
#include"check.h"
#include"date_sheet.h"
#include"Menu.h"
#include"Paper.h"
#include"auth.h"
#include"Message.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

check c; date_sheet dd; Menu MM; auth roll; paper pp; Message MG;
int rollnumber;
void student::result()
{
	bool isf = 0;
	int choice;
	string sab;
	int rs, om;
	//system("cls");
	cout << "Select Subject to View your result : " << endl;
	cout << "==>";
	for (int i = 0; i <= 4; i++) {
		cout << "Press " << i + 1 << " to " << subject[i] << endl;
	}
	cin >> choice;
	choice = choice - 1;
	if (choice >= 0 && choice < 5)
	{
		ifstream res;
		res.open("C:/SE/Examination_System/result.txt");
		int f = 0;
		string line;
		while (getline(res,line)) {
			istringstream iss(line);
			iss >> f >> sab >> rs >> om;
			if (f==1) {
				if (valid == rs && sab == subject[choice]) {
					cout << "Your Total Marks are : " << om << endl;
					isf = 1;
				}
				//break;
			}
		}
		cout << endl;
		if (!isf) {
			cout << "\nPaper is not check Yet. \n";
			char r;
			cout << "Press Any key to go back : ";
			MM.menu();
		}
	}
}

auth au;
int student::log()
{
	au.log1();
	int user = au.getUser();
	int passw = au.getPassw();
	login(user, passw);
	return user;
}

void student::give_paper()
{
	cout << "Welcome Gave Your Paper " << endl;
	cout << "Select Subject : " << endl;
	for (int i = 0; i < 5; i++) {
		cout << "Press " << i + 1 << " For " << subject[i] << endl;
	}
	cout << "Select Subject to Anwer: \n==>";
	int ch;
	cin >> ch;

	if (ch > 0 && ch < 7) {

		ifstream file;
		ofstream ans;
		file.open(file_of_papers[ch - 1]);
		ans.open(Ans_sheet[ch - 1], ios::app);
		string str;
		if (!file || !ans) {
			cout << "Something went wrong Try again...";
		}
		else {
			string q; string m;
			cin.ignore();
			string check;
			while (getline(file, check))
			{
				istringstream iss(check);
				iss >> q >> m;
				cout << "Q : " << q << "\t\t\t Marks : " << m << endl;
				cin.getline(answer, 256);
				ans << rollnumber << " " << answer << endl;
			}
			file.close();
		}
	}
}

void student::view_paperAns(int& user)
{
	rollnumber = user;
	cout << "Welcome To View Paper Answer " << endl;
	cout << "Select Subject : " << endl;
	for (int i = 0; i <= 4; i++) {
		cout << "Press " << i+1 << " For " << subject[i] << endl;
	}
	cout << "Select Subject to Anwer: \n==>";
	int ch;
	cin >> ch;
	if (ch > 0 && ch < 7) {
		ifstream file;
		file.open(Ans_of_paper[ch - 1]);
		string str;
		if (!file) {
			cout << "Something went wrong Try again...";
		}

		if (c.check_answered(user, ch)==1) {
			string a;
			cin.ignore();
			int k = 1;
			while (std::getline(file, a))
			{
				istringstream iss(a);
				iss >> a;
				cout << "Answer of question " << k << " : " << a << endl;
				k++;
			}
			file.close();
		}
		else {
			cout << "Paper has not check ,please Wait for Your Teacher to Graded it....";
		}
	}
}

void student::login(int& user, int& pasw)
{
	valid = user;
	if (c.check_student(user, pasw) == 1) {
		rollnumber = user;
		int roll = user;
	st_menu:
		do {
			//system("cls");
			cout << "=====\tWELCOME Roll No. " << user <<"\t=====" << endl;
			cout << "Press\n1. To View Date_sheet \n";
			cout << "2. To Give Paper \n";
			cout << "3. To View Reults\n";
			cout << "4. Self-Practice Questions\n";
			cout << "5. View Answer of Paper\n";
			cout << "6. Message Teacher for Question\n";
			cout << "7. Teacher's Reply\n";
			cout << "8. Log out\n";
			cout << "==>";
			cin >> choice;
			switch (choice)
			{
			case 1:
				dd.view_datesheet();
				char r;
				cout << "\nPress Any key to Go back : "; cin >> r;
				goto st_menu;
				break;
			case 2:
				give_paper();
				cout << "\nPress Any key to Go back : ";
				getchar();
				break;
			case 3:
				result();
				cout << "\nPress Any key to Go back : ";
				getchar();
				goto st_menu;
				break;
			case 4:
				pp.practice();
				cout << "\nPress Any key to Go back : ";
				getchar();
				goto st_menu;
				break;
			case 5:
				view_paperAns(user);
				cout << "\nPress Any key to Go back : ";
				getchar();
				goto st_menu;
				break;
			case 6:
				MG.Ques_toTeacher(roll);
				cout << "\nPress Any key to Go back : ";
				getchar();
				goto st_menu;
				break;
			case 7:
				MG.viewTeacherReply();
				cout << "\nPress Any key to Go back : ";
				getchar();
				goto st_menu;
				break;
			case 8:
				MM.menu();
			default:
				cout << "INVALID CHOICE";
				cout << "press 1 to try again";
				cin >> ret;
				break;
			}
		} while (ret == 1);
	}
	else {
		cout << "Roll No. Not found Ask Admin to register You or try again.\nPress any Key to go back : ";
		char r;
		cin >> r;
		MM.menu();
	}
}
