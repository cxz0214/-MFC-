#pragma once
#include "s_classinfo.h"
class CStudentChangeADD
{
public:
	CStudentChangeADD();
	~CStudentChangeADD();
	void SetClassObj(int c_number, int s_number, int t_number, int c_grade = 0);
	void SetClassSet(Cs_classinfo* p);
	void AddToClasstable();
private:
	Cs_classinfo* pClassInforSet;
	int C_number;
	int S_number;
	int T_number;
	int C_grade;
};

