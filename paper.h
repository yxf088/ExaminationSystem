#pragma once
class paper
{
private:
	int each_marks;
	int total_marks = 0;
	int total_qes;
	char question[1000];
	char ans[1000];
public:
	void make_paper() ;
	void practice();
};

