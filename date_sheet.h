
#pragma once
#include <iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;
class date_sheet
{
protected:
	string s;
	int d,
		m,
		y;
	int starting_time,
		ending_time;
public:
	//For Date_sheet
	int getdate();
	int getmonth();
	int getyear();
	int get_st();
	int get_et();
	void view_datesheet() ;
};

