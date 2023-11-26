#pragma once
class teacher
{
private:
	int choice;
	int usr;
	int check_roll;
	int ret = 0;
	int obtained_marks;

public:
	void log() ;
	void login(int &user, int &pasw) ;
	void check_paper() ;

};

