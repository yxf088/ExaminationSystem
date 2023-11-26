#include "Menu.h"
#include"admin.h"
#include"auth.h"
#include"student.h"
#include"teacher.h"
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
#include "first.h"
admin A; student s; teacher t;

void Menu::menu() {
	int choice;
	int ret = 0;
	do {
		//system("cls");
		cout << "================\t\tEXAM PORTAL\t\t===============\nPress:\n";
		cout << "1. For Admin" << endl;
		cout << "2. For Student" << endl;
		cout << "3. For Teacher" << endl;
		cout << "4. To Exit" << endl;
		cout << "Select :  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			A.log();
			menu();
			break;
		case 2:
			s.log();
			menu();
			break;
		case 3:
			t.log();
			menu();
			break;
		case 4:
			cout << "\n\t******Thanks for Using******\n";
			exit(1);
		default:
			cout << "Invalid Choice Press 0 to Try Again else Exit..";
			cin >> ret;
			break;
		}
	} while (ret == 0);
}