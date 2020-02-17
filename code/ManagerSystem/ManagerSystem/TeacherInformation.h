#pragma once
#include "teacherinfo.h"
class TeacherInformation
{
public:
	TeacherInformation();
	~TeacherInformation();
	void SetTeacherObJ(int number, CString name, CString sex, CString depart);
	void SetTeacherSet(Cteacherinfo* p);
	void AddTeacherObj();
private:
	int teacher_num;
	CString teacher_name;
	CString teacher_sex;
	CString teacher_department;
	Cteacherinfo* pTeacherSet;
};

