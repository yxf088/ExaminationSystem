#include "date_sheet.h"
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
void date_sheet::view_datesheet()
{
	ifstream file;
	file.open("C:/SE/Examination_System/date_sheet.txt");
	if (!file) {
		cout << "File Not Found ";
	}
	cout << "\n\t\t\t\t------DateSheet-----\n\n";
	while (!file.eof()) {
		file >> s >> d >> m >> y >> starting_time >> ending_time;
		cout << "Subject : " << s << "\tDate : " << d << "-" << m << "-" << y << "\t\tStarting Time : " << starting_time << " \t\tEnding Time : " << ending_time << endl;
	}
	file.close();

}

int date_sheet::getdate()
{
	return d;
}
int date_sheet::getmonth()
{
	return m;
}
int date_sheet::getyear()
{
	return y;
}
int date_sheet::get_st()
{
	return starting_time;
}
int date_sheet::get_et()
{
	return ending_time;
}
